#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main (int argc, const char * argv[])
{
	cJSON *json = NULL;
	cJSON *json_start = NULL;
	cJSON *json_number = NULL;

	char text[] = "{\"start\":\"hello world !\",\"number\":48}";

	if (NULL == (json = cJSON_Parse(text)))
	{
		printf("Error before: [%s]\n",cJSON_GetErrorPtr());
		return -1;
	}

	json_start = cJSON_GetObjectItem(json , "start");
	if (NULL != json_start && json_start->type == cJSON_String)
	{
		printf("start:%s\n",json_start->valuestring);
	}
	json_number = cJSON_GetObjectItem(json , "number");
	if (NULL != json_number && json_number->type == cJSON_Number)
	{
		printf("number:%d\n",json_number->valueint);
	}
	cJSON_Delete(json);
	return 0;
}