#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
long long length[50],patty[50];

long long ans(int n,long long x){
    if(n==0&&x>=1) return 1;
    if(x<=1) return 0;
    long long ret=0;
    if(x<=length[n-1]+1) ret=ans(n-1,x-1);
    if(x>=length[n-1]+2) ret=patty[n-1]+1+ans(n-1,x-length[n-1]-2);
    return ret;
}

signed main(){
    int N;
    long long X;
    cin>>N>>X;
    length[0]=1;
    patty[0]=1;
    REP(i,N-1){ 
        length[i+1]=2*length[i]+3;
        patty[i+1]=2*patty[i]+1;
    }
    cout<<ans(N,X)<<endl;
}