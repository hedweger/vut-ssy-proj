/*
 * app_header.h
 *
 * Created: 4/28/2025 12:30:13
 *  Author: Student
 */ 


#ifndef APP_HEADER_H_
#define APP_HEADER_H_
#include <stdbool.h>

typedef enum AppState_t {
	INIT,
	IDLE,
} AppState_t;

typedef enum AppMsgType_t {
	APP_NACK, // Negative Acknowledgement
	APP_ACK,  // Acknowledgement
	// Client msgs
	DISCOVER,  // c -> s  | Discover router
	DECLINE,   // c -> s  | Decline address config (prompts another OFFER)
	REQUEST,   // c -> s  | Request address config
	APP_SLEEP, // c -> s | Announce sleep mode
	RECONNECT, // c -> s | Wake up
	APPDATA,   // c -> s | Send data
	// Server msgs
	RELEASE,      // s -> c  | Release address config
	OFFER,        // s -> c  | Offer address config
	WAKE_UP,      // s -> c  | Wake up node
	REQUEST_DATA, // s -> c | Request data
} AppMsgType_t;

typedef enum SensorType_t {
	WEIGHT_SENSOR,
	OTHER,
} SensorType_t;

typedef struct AppMsg_t {
	// header
	uint8_t size;
	AppMsgType_t msgType;
	// data
	uint8_t *data;
} AppMsg_t;

#define ROUTE_TABLE_SIZE 256
typedef struct RouteTable_t {
	uint16_t addr;
	uint8_t endpoint;
	SensorType_t type;
	bool sleeping;
	bool in_use;
} RouteTable_t;


#endif /* APP_HEADER_H_ */