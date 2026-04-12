#include <stdio.h>
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    if(a<b){
        puts("a < b");
    }else if(b<a){
        puts("a > b");
    }else{
        puts("a == b");
    }
    return 0;
}