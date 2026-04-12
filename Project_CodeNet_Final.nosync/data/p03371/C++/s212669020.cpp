#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int main(){
    int A,B,C,x,y;
    scanf("%d%d%d%d%d",&A,&B,&C,&x,&y);
    int ans = 0;
    int z = min(x,y), m = max(x,y);
    int tmp = C*2*m;
    if(A+B < C*2){
        ans += z*(A+B);
    }
    else ans += z*C*2;
    x -= z;
    y -= z;
    while(x) {
        ans += A;
        x --;
    }
    while(y){
        ans += B;
        y --;
    }
    ans = min(ans,tmp);
    printf("%d\n",ans);
    return 0;
}
