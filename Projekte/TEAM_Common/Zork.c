/*
 * Zork.c
 *
 *  Created on: 16.11.2018
 *      Author: Luca Gamma
 */

#include "Platform.h"
#if PL_CONFIG_HAS_ZORK
#include "Zork.h"
#include "FRTOS1.h"
#include "Shell.h"
#include "Zork\zork_config.h"

void _exit(int notuse) {
	CLS1_SendStr("exit Zork Game\n", CLS1_GetStdio()->stdErr);
	vTaskDelete(NULL); //self Kill
}
static void ZorkTask ( void *pvParameters ) {
	//vTaskSuspend(NULL);
	zork_config();
	run_zork_game();
	CLS1_SendStr("CIAO ZORK!", CLS1_GetStdio()->stdErr);
	//vTaskDelete(NULL);
}

void Zork_Init(void) {
	if(xTaskCreate(ZorkTask,
			"Zork",
			900/sizeof(StackType_t) ,
			NULL,
			tskIDLE_PRIORITY ,
			NULL
			) != pdPASS){
		//ERROR Handling
		for(;;){}
	}
}

#endif /* PL_CONFIG_HAS_ZORG */


