#include<stor_manager.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

#define TIMESTAMP_LENGTH 14

int filter(const struct dirent* entry)
{
	if(entry->d_type != DT_REG)
		return 0;

	for(int i = 0; i < TIMESTAMP_LENGTH; i++)
		if((entry->d_name[i] > '9') || (entry->d_name[i] < '0'))
			return 0;

	if(strncmp(entry->d_name + TIMESTAMP_LENGTH, ".kdbx", 5) != 0)
		return 0;

	if(entry->d_name[TIMESTAMP_LENGTH+5] != '\0')
		return 0;

	return 1;
}

char* lastBackup(char* prefix){
}

char* SM_getPath(char* timestamp, char* prefix)
{
	char* res = (char*)malloc(strlen(prefix)+TIMESTAMP_LENGTH+6);
	strcpy(res, prefix);
	strncat(res, timestamp, TIMESTAMP_LENGTH);
	strncat(res, ".kdbx", 5);
	return res;
}

char* SM_update(char* backup_prefix, char* db_path)
{
	
}
