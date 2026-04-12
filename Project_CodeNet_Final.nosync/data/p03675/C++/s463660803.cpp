#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int n,x;
int a[610000];

int main(){
    scanf("%d",&n);
    int h=300000,t=299999;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        if(i&1)a[++t]=x;
        else a[--h]=x;
    }if(n&1){
        for(int i=t;i>=h;i--){
            printf("%d ",a[i]);
        }
    }else{
        for(int i=h;i<=t;i++){
            printf("%d ",a[i]);
        }
    }return 0;
}