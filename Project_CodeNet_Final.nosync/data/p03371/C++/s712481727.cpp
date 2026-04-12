#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;
ll min (ll a, ll b){ return (a<b)?a:b;}
int A,B,C,X,Y;
int main(void){
    scanf("%d %d %d %d %d",&A,&B,&C,&X,&Y);
    int money = 0;
    
    int common = min(X,Y);
    int rest = (X<Y)? Y-common: X-common;
    
    if(C*2<A+B){
        money += common*2*C;
    }else{
        money += common*(A+B);
    }

    if(X<Y){
        if(2*C<B) money += rest*2*C;
        else      money += rest*B;
    }else{
        if(2*C<A) money += rest*2*C;
        else      money += rest*A;
    }
    
    printf("%d\n",money);
}