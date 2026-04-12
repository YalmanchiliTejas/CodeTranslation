#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 10000000000

int main(){
  ll N,X,M;
  cin>>N>>X>>M;
  vector<ll> A(M+2);
  set<ll> s;
  A[0]=X;
  s.insert(A[0]);
  int left,right;
  for(int i=1;i<=M+1;i++){
    A[i]=A[i-1]*A[i-1]%M;
    if(s.count(A[i])==1){
      right=i;
      break;
    }
    s.insert(A[i]);
  }
  for(int i=0;i<right;i++){
    if(A[i]==A[right]){
      left=i;
      break;
    }
  }

  ll ans=0;
  for(int i=0;i<left;i++){
    ans+=A[i];
    N--;
    if(N==0){
      break;
    }
  }
  if(N==0){
    cout<<ans<<endl;
  }else{
    ll cnt=N/((ll)right-(ll)left);
    ll sub=0;
    for(int i=left;i<right;i++){
      sub+=A[i];
    }
    ans+=cnt*sub;
    ll res=N%((ll)right-(ll)left);
    for(int i=left;i<left+res;i++){
      ans+=A[i];
    }
    cout<<ans<<endl;
  }
}
