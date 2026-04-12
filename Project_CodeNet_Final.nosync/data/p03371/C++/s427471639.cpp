#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int Max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}

int Min(int a,int b){
    if(a<b)
        return a;
    else
        return b;
}

int main(){
 int ans,a,b,c,x,y;
 int temp;
 while(scanf("%d%d%d%d%d",&a,&b,&c,&x,&y)==5){
    ans=0;
    if(a+b>c*2){
        ans+=Min(x,y)*c*2;
        temp=Min(x,y);
        x-=temp;
        y-=temp;
        if(x>0){
            if(a>c*2){
                ans+=x*c*2;
            }
            else{
                ans+=x*a;
            }
        }
        if(y>0){
            if(b>c*2){
                ans+=y*c*2;
            }
            else{
                ans+=y*b;
            }
        }
    }
    else{
        ans=x*a+y*b;
    }
    printf("%d\n",ans);
 }
    return 0;
}
