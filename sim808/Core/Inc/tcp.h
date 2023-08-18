/*
 * tcp.h
 *
 *  Created on: Aug 18, 2023
 *      Author: Abdullah
 */

#ifndef INC_TCP_H_
#define INC_TCP_H_

#include "main.h"
#include <stdio.h>
#include "stm32f1xx_hal.h"
#include "string.h"

#define MODULE_USART1 huart1
#define MODULE_USART3 huart3

extern UART_HandleTypeDef MODULE_USART1;
extern UART_HandleTypeDef MODULE_USART3;

void sendCommandCheck(char *cmd, char *response, char *rxBuffer1);
void sendCommand(char *cmd);
void sendTcpServer(char *rxBuffer3);
void connect_TCP(char *ip, char *port, char *rxBuffer1);

#endif /* INC_TCP_H_ */
