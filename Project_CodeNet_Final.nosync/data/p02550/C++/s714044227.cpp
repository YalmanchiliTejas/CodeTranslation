#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD=998244353;
const long double PI=3.14159265358979;
const ll MAX=0;

ll DP[600020];

int main() {
  ll N,X,M;
  cin>>N>>X>>M;ll A[M];//ll sum[M];
  rep(i,M){
    A[i]=0;//Sum[i]=0;
  }
  ll p=1,ans=0;
  while(p<=N){
    if(A[X]!=0){
      break;
    }
    A[X]=p;ans+=X;
    X=X*X;X%=M;p++;
  }
  ll d=p-A[X];ll dsum=0;
  rep(i,d){
    dsum+=X;X*=X;X%=M;
  }
  N-=p;N++;ans+=N/d*dsum;ll m=N%d;
  rep(i,m){
    ans+=X;X*=X;X%=M;
  }
  cout<<ans;
  
  
}

