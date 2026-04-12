#include<iostream>
using namespace std;

int main(){
    int r,g,b;
    scanf("%d%d%d",&r,&g,&b);

    int n = r*100 + g*10 + b;
    if(n%4==0){
        printf("YES");
    }else{
        printf("NO");
    }
}