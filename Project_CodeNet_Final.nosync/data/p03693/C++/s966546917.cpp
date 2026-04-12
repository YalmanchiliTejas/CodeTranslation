#include <iostream>
#include<string>
#include<algorithm>
#include<stdio.h>

using namespace std;

int main(){
    int r,g,b;
    scanf("%d %d %d",&r,&g,&b);//caution!
    if((100*r + 10*g + b) % 4 == 0){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}