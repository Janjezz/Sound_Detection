#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#define BUF_LEN 80

int main()
{
    int file_desc;
    int ret_val;
    char tmp[BUF_LEN];

    /* Open dummy file. */
    file_desc = open("soundDetection", O_RDWR);

    if(file_desc < 0)
    {
        printf("Error, 'soundDetection' not opened\n");
        return -1;
    }

    printf("************SOUND DETECTION DRIVER APP**************\n\n");
    char option = '0';
    int optionInt = 0;

    do
    {
        printf("1. Start sound detection\n");
        printf("2. Stop sound detection\n");
        printf("3. Exit App\n");
        printf("Unesite broj zeljene komande: ");
        option = getchar();
        optionInt = atoi(&option);
        switch(optionInt)
        {
            case 1:
                ret_val = write(file_desc, "1", 2);
                printf("Started sound detection!");
                break;
            
            case 2:
                ret_val = write(file_desc, "2", 2);
                printf("Stopped sound detection!");
                break;
            case 3:
                printf("Exiting...");
                break;
        }

    }
    while(optionInt != 3);

    close(file_desc);
    
    return 0;
}
