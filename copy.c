/*************************************************************************
	> File Name: copy.c
	> Author: 
	> Mail: 
	> Created Time: 2017年08月05日 星期六 14时58分51秒
 ************************************************************************/

#include<stdio.h>
#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"

#include "unistd.h"
#define  PERMS 0666
#define  DUMMY 0
#define BUFSIZE 1024
int main(int argc, char const *argv[])
{
        int source_fd,target_fd,num;
        char iobuffer[BUFSIZE];
        if (argc!=3)
    {
                printf("usage:copy sourcefile targetfile\n" );
            return 1;
            
    }
        if((source_fd=open(*(argv+1),O_RDONLY|DUMMY))==-1)
            {
                        printf("sourcefile open error\n");
                        return 2;
                    
            }
    if ((target_fd=open(*(argv+2),O_WRONLY|O_CREAT,PERMS)) ==-1)
            {
                        printf("targetfile opne error\n");
                        return 3;
                    
            }
           
           
               while((num=read(source_fd,iobuffer,BUFSIZE))>0)
                if (write(target_fd,iobuffer,num)!=num)
            {
                            printf("targetfile write error\n");
                            return 4;
                        
            }
                close(source_fd);
                close(target_fd);
                return 0;
           }
           
           
           
           
