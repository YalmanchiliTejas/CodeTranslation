/* 
 * File:   main.c
 * Author: minohara
 *
 * Created on 2014/12/10, 15:21
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * , char** argv) {
    int a,b;
 */
int main(int argc , char** argv) {
    int a,b;
    a=0;
    b=0;
    scanf("%d %d",&a,&b);
    if(a<b){
        printf("a < b\n",a,b);
    }
    else if(a>b){
        printf("a > b\n",a,b);
    }
    else{
        printf("a == b\n",a,b);
    }
        
    

    return (EXIT_SUCCESS);
}