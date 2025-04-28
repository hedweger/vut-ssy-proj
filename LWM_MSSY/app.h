/*
 * app.h
 *
 * Created: 4/28/2025 11:57:09
 *  Author: Student
 */ 


#ifndef APP_H_
#define APP_H_


#include <avr/io.h>
#include <stdint.h>
#include <string.h>

#include "app_header.h"
#include "halBoard.h"
#include "halUart.h"
#include "nwk.h"
#include "nwkDataReq.h"
#include "nwkRx.h"
#include "phy.h"
#include "sysTimer.h"

#define APP_HEADER_SIZE 2
#define DEBUG_PRINT



void APP_init(void);
void APP_timerHandler(SYS_Timer_t *timer);
bool APP_dataRecv(NWK_DataInd_t *ind);
void APP_dataOut(void);
void APP_dataConf(NWK_DataReq_t *req);
void APP_msgCreate(void);


#endif /* APP_H_ */