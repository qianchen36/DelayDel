/**
 * @file filelist.c
 * @author qianchen
 * @brief 
 * @version 1.0
 * @date 2022-10-07
 * 
 * @copyright qianchen.org.cn Copyright (c) 2022
 * 
 */


#include "filelist.h"


/**
 * @brief Init FileList
 * 
 * @param _handler FileList Handler
 * @return int 0 Success, -1 Failed
 */
int filelist_init(filelist *_handler)
{
    // Create First Node
    filelist *p = (filelist *) malloc(sizeof(filelist));
    if (p == NULL) return -1;

    // Init First Node
    (*p).index = 0;
    (*p).name = NULL;
    (*p).path = NULL;
    (*p).time = 0;
    (*p).size = 0;
    (*p).next = NULL;

    // Set Handler
    _handler = p;

    return 0;
}


/**
 * @brief Add a Node to FileList
 * 
 * @param _handler FileList Handler
 * @return int 0 Success, -1 Failed
 */
int filelist_add(filelist *_handler)
{
    filelist *p = _handler;

    // Find the Last Node
    while ((*p).next != NULL)
    {
        p = (*p).next;
    }
    
    // Add New Node
    filelist *new = (filelist *) malloc(sizeof(filelist));
    if (new == NULL) return -1;

    // Init New Node
    (*new).index = (*p).index + 1;
    (*new).name = NULL;
    (*new).path = NULL;
    (*new).time = 0;
    (*new).size = 0;
    (*new).next = NULL;

    // Set Pointer
    (*p).next = new;

    return 0;
}


/**
 * @brief Delete Selected Node
 * 
 * @param _handler FileList Handler
 * @param _index Node Index
 * @return int 0 Success, -1 Failed
 */
int filelist_del(filelist *_handler, int _index)
{
    filelist *p = _handler;

    // Find the Node
    while ((*p).index != _index - 1)
    {
        p = (*p).next;
    }

    filelist *cur = (*p).next;
    
    // Delete the Node
    (*p).next = (*cur).next;

    free((*cur).name);
    free((*cur).path);
    free(cur);

    // Update the Index
    while ((*p).next != NULL)
    {
        p = (*p).next;
        (*p).index = (*p).index - 1;
    }

    return 0;
}


/**
 * @brief Free FileList
 * 
 * @param _handler FileList Handler
 * @return int 0 Success, -1 Failed
 */
int filelist_free(filelist *_handler)
{
    filelist *p = _handler;

    // Free All Node
    if ((*p).next != NULL)
    {
        filelist_free((*p).next);
    }
    
    // Free Current Node
    free((*p).name);
    free((*p).path);
    free(p);

    _handler = NULL;

    return 0;
}


/**
 * @brief Edit Selected Node
 * 
 * @param _handler FileList Handler
 * @param _index Node Index
 * @param _filedata File Datas
 * @param _path File Path
 * @return int 
 */
int filelist_edit(filelist *_handler, int _index, struct _finddata_t *_filedata, char *_path)
{
    filelist *p = _handler;

    // Find the Node
    while ((*p).index != _index)
    {
        p = (*p).next;
    }

    // Edit the Node
    (*p).name = (char *) malloc(sizeof((*_filedata).name));
    strcpy((*p).name, (*_filedata).name);
    (*p).path = (char *) malloc(sizeof(_path));
    strcpy((*p).path, _path);
    (*p).time = (*_filedata).time_create;
    (*p).size = (*_filedata).size;

    return 0;
}
