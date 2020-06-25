#ifndef __ANO_LINK_H_
#define __ANO_LINK_H_

#include "../user/config.h"

typedef struct
{
    float p;
    float i;
    float d;
} Vector3f_pid;

void ANO_SEND_StateMachine(void); //��������ѭ������

void ANO_DT_Data_Receive_Prepare(uint8_t data); //ANO����վ���ݽ���

void ANO_DT_Data_Receive_Anl(uint8_t *data_buf, uint8_t num); //ANO���ݽ���

#endif
