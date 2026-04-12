#include <bits/stdc++.h>

using namespace std;

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)
#define SCANFD(x) scanf("%d",&x)

int main(){
    int N;
    int a[200001];
    int b[200001];
    int buf;

    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%d",&a[i]);

    if(N%2==0){
        int i=0;
        buf=N;
        while(buf>0){
            b[i] = a[buf];
            buf -= 2;
            i++;
        }
        buf=1;
        while(buf<N+1){
            b[i] = a[buf];
            buf+=2;
            i++;
        }
    }else{
        int i=0;
        buf = N;
        while(buf>0){
            b[i] = a[buf];
            buf -= 2;
            i++;
        }
                    
        buf=2;
        while(buf<N+1){
            b[i] = a[buf];
            buf+=2;
            i++;
        }
    }
    
    for(int i=0;i<N;i++)
        printf("%d ",b[i]);

    printf("\n");

    return 0;
}
    