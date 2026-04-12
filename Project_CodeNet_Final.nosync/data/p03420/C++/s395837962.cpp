#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
        int N,K;scanf("%d%d",&N,&K);
        long long ans=0;

        for(int i=K+1;i<=N;++i){
                for(int j=0;j<=N;j+=i){
                        ans+=max(min(N,j+i-1)-max(1,j+K)+1,0);
                }   
        }   
        cout<<ans<<endl;
}
