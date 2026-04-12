#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    int count=0;
    int i;
    int length;

    scanf("%s", str);
    if(strlen(str)!=3){
        return 0;
    }

    for(i=0; i<3; i++){
        if(str[i]=='A'){
            count++;
        }else if(str[i]=='B'){
            count--;
        }
    }

    if((-3<count && count<3) && count!=0){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}