/**
 * @desc: �˲�����
 */

#include "filter.h"
#include <math.h>

/* ð�� ��ֵ�˲�  */
uint32_t bubble_filter(uint32_t *value)
{
    uint8_t i, j, swapFlag; //������־λ
    uint32_t res = 0;       //reserve �ݴ�
    uint32_t med = 0;       //��ֵ

    for (j = 0; j < 10 - 1; j++)
    {
        swapFlag = 0; //ÿһ����ѭ������
        for (i = 0; i < 9 - j; i++)
        {
            if (value[i] > value[i + 1])
            { //>����   <����
                res = value[i];
                value[i] = value[i + 1];
                value[i + 1] = res;

                swapFlag = 1; //��������1
            }
        }
        if (0 == swapFlag)
            break; //δ��������������ǰ����
    }
    med = (*(value + 4) + *(value + 5) + *(value + 6)) / 3; //�м�ƽ��ֵ
    return med;
}

/*
����p�ĳ�ֵ�������ȡ�����ǲ���Ϊ0��Ϊ0�Ļ��������˲�������Ϊ�Ѿ��������˲����ˣ� 
q,r��ֵ��Ҫ�����Գ����������˾���(������¶ȼ��ж��ƣ��Լ���ĳ������ж�ǿ)
q���������˲����������ʵ�����ߵ�����̶ȣ�qԽ��Խ�ӽ���
r�������˲��������ƽ���̶ȣ�rԽ��Խƽ���� 
*/
float kalman_filter(float *Original_Data)
{
    static float prevData = 0;
    static float p = 10, q = 0.0001, r = 0.001, kGain = 0;

    p = p + q;
    kGain = p / (p + r);

    *Original_Data = prevData + (kGain * (*Original_Data - prevData));
    p = (1 - kGain) * p;

    prevData = *Original_Data;

    return *Original_Data;
}
