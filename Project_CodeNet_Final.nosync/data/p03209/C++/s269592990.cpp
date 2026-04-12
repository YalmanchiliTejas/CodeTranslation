#include <bits/stdc++.h>
using namespace std;

long F[50],L[50];

long func(int n,long x){
    if(n==0){
        return 1;
    }else if(x==1){
        return 0;
    }else if(x==F[n]){
        return L[n];
    }else if(x==F[n-1]+2){
        return L[n-1]+1;
    }else if(x<=F[n-1]+1){
        return func(n-1,x-1);
    }else{
        return func(n-1,x-F[n-1]-2)+L[n-1]+1;
    }
}

int main(){
    int N;long X;
    cin>>N>>X;
    F[0]=1;L[0]=1;
    for(int i=1;i<=N;i++){
        F[i]=2*F[i-1]+3;
        L[i]=2*L[i-1]+1;
    }cout<<func(N,X)<<endl;
}