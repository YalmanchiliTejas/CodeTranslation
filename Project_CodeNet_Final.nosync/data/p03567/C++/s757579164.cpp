#include<stdio.h>
#include<string>
int main(void){
    char a[5];
    char c[]="A";
    char d[]="C";
    int b,i;
    scanf("%s",a);
    
    b=0;
    for(i=0;i<5;i++){
        if(a[i]==c[0]){
            if(a[i+1]==d[0]){
            b=b+1;
            }else{
                b=b+0;
            }
        }else{
        b=b+0;
        }
    }
    
    if(b>=1)
    printf("Yes");
    else
    printf("No");

}