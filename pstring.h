/*
** pstring.h  Copyright (C) 2023, 2024  Mahdi Hosseini Asaad
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

char *global;


int find ( char main[], char flag, int time ) // find the flag char from string
{
    register char indexcpy = 1; // indexcpy in here for time var
    for ( register char index = 0 ; index < strlen (main) ; ++index )
    {
        switch ( main[(int)index]==flag )
        {
            case 1:
                switch ( indexcpy==time ) 
                {
                    case 1:
                        return index;
                    default:
                        ++indexcpy;
                }
        }
    }
    return -1;
}


char* g_strdup_printf ( const char* format, ... ) // stdarg.h
{
    va_list args;
    va_start(args, format);

    va_list args_copy;
    va_copy(args_copy, args);
    int len = vsnprintf(NULL, 0, format, args_copy);
    va_end(args_copy);

    char* str = (char*)malloc((len + 1) * sizeof(char));

    vsnprintf(str, len + 1, format, args);

    va_end(args);

    return str;
}



int charnum ( char main[], char flag ) // how many characters in string
{
    int ret_val = 0;
    for ( register char index = 0 ; index < strlen (main) ; ++index )
    {
        switch (main[(int)index]==flag)
        {
            case 1:
                ++ret_val;
            default:
                break;
        }
    }
    return ret_val;
}



char *replace_char ( char main [], char flag, char r_flag ) // replace char in the string
{
    int chrnum = charnum (main, flag);
    char register inx=0;
    for ( register char index = 0 ; index <= chrnum ; ++index )
    {
        inx = find (main, flag, 1);
        switch ( inx )
        {
            case -1:
                break;
            default:
                main [(int)inx] = r_flag;

        }
    }
    return main;
}

//#########################################################

char * separate ( char main[], int index1, int index2 ) // crop string from index1 to index2
{
    global = (char *) calloc ((index2-index1+1), sizeof (char));
    register char indexcpy = 0; // char -> int : for optimize
    for ( register char index = 0 ; index < strlen (main) ; ++index )
    {
        switch (index >= index1)
        {
            case 1:
                switch ( index < index2 )
                {
                    case 1:
                        global[(int)indexcpy]=main[(int)index];
                        ++indexcpy;
                }
        }
    }
    return global;
}

char * remove_i2i ( char text[], int in1, int in2 ) // cut your text from index of in1 to in2 and replace it with space
{
    register char index = 0;
    global = (char *) calloc (strlen (text)+1, sizeof (char));
    for ( register char i = 0 ; i<strlen (text) ; ++i )
    {
        if ( (index >= in1 ) && (index <=in2))
        {
            global [(int)index]=' ';
            ++index;
            continue;
        }
        global [(int)index] = text [(int)i];
        ++index;
    }
    return global;
}
//#########################################################

//*********************************************************************************
char * Distance (  char main[] ) // remove space before other characters
{
    global = (char *) calloc (strlen (main), sizeof (char)); // please optimize
    strcpy   (global, main); // global == main
    for ( register char index = 0 ; index < strlen (main) ; ++index )
    {
        switch ( global [0] )
        {
            case ' ':
                strcpy (global, separate ( main, (int)index+1, strlen (main)));
                break;
            default:
                return global;
        }
    }
}

char *Distance_end ( char main[] ) // remove space from end of string
{
    global = (char *) calloc (strlen (main)+1, sizeof (char));
    strcpy (global, main);

    for ( register char index = 0 ; index < strlen (main) ; ++index )
    {
        switch (main[strlen (main)-1-index])
        {
            case ' ':
                switch (global[strlen (main)-2-index])
                {
                    case ' ':
                        break;
                    default:
                        global[strlen(global)-index-1]='\0';
                }
                break;
            default:
                return global;
        }
    }
    return global;
}

char *remove_all_space ( char main[] )
{
    global = (char *) calloc (strlen (main), sizeof (char));
    for ( register char index = 0, indexcpy = 0 ; index < strlen (main) ; ++index )
    {
        switch (main[(int)index])
        {
            case ' ':
                break;
            default:
                global[(int)indexcpy]=main[(int)index];
                ++indexcpy;
        }
    }
    return global;
}
//*********************************************************************************

/*
** pstring.h  Copyright (C) 2023, 2024  Mahdi Hosseini Asaad
*/