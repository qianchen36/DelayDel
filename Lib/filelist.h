/**
 * @file filelist.h
 * @author qianchen
 * @brief 
 * @version 1.0
 * @date 2022-10-07
 * 
 * @copyright qianchen.org.cn Copyright (c) 2022
 * 
 */


#include <io.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef __FILELIST_H__
#define __FILELIST_H__

/**
 * @brief FileList Node
 * 
 */
typedef struct
{
    int index;
    char *name;
    char *path;
    time_t time;
    _fsize_t size;
    struct filedata_list *next;

} filelist;


int filelist_init(filelist *_handler);
int filelist_add(filelist *_handler);
int filelist_del(filelist *_handler, int _index);
int filelist_free(filelist *_handler);
int filelist_edit(filelist *_handler, int _index, struct _finddata_t *filedata, char *_path);

#endif
