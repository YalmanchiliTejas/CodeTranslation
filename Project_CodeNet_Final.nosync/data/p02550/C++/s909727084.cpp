#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll N,X,M,S;
  cin >> N >> X >> M;
  ll m[M],n[M+1];
  S=X;
  for(ll i=0;i<M;i++)m[i]=-1;
  m[X]=1;
  n[1]=X;
  for(ll i=2;i<=N;i++){
    X=(X*X)%M;
    if(m[X]!=-1){
      ll y=(N-i+1)/(i-m[X]);
      if(y>0){
        ll o=0;
        for(ll j=m[X];j<i;j++)o+=n[j];
        S+=o*y;
      }
      ll l=(N-i+1)%(i-m[X]);
      for(ll j=m[X];j<m[X]+l;j++)S+=n[j];
     cout << S;
      return 0;
    }
    m[X]=i;
    n[i]=X;
    S+=X;
  }
  cout << S;
}