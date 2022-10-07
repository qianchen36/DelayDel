/**
 * @file delaydel_main.c
 * @author qianchen
 * @brief 
 * @version 1.0
 * @date 2022-10-07
 * 
 * @copyright qianchen.org.cn Copyright (c) 2022
 * 
 */


#include "delaydel_main.h"


int main(int argc, const char *argv[])
{
    // Console Init
    system("cls");
    system("title DelayDel 1.0");

    printf("Current Dir: %s\n", getcwd(NULL, 0));
    _sleep(1000);

    struct _finddata_t filedata;
    struct tm filetime;

    
    intptr_t hFile;
    hFile = _findfirst("*.c", &filedata);
    filetime = *localtime(&filedata.time_create);
    printf(" File Name: %s\n File Create TimeStamp: %d\n File Create Time: %d/%d/%d %02d:%02d\n",
            filedata.name, filedata.time_create, filetime.tm_year + 1900, filetime.tm_mon + 1, filetime.tm_mday,
            filetime.tm_hour, filetime.tm_min);

    _findnext(hFile, &filedata);
    _findclose(hFile);
    filetime = *localtime(&filedata.time_create);
    printf(" File Name: %s\n File Create TimeStamp: %d\n File Create Time: %d/%d/%d %02d:%02d\n",
            filedata.name, filedata.time_create, filetime.tm_year + 1900, filetime.tm_mon + 1, filetime.tm_mday,
            filetime.tm_hour, filetime.tm_min);
    

    return 0;
}
