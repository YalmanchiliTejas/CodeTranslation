#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
using namespace std;
#define ll long long

ll burger(ll L,ll X,pair<ll,ll> Lburg[]){
  ll ans;
  if(L==0)ans=1;
  else{
    if(X==1){
      ans=0;
    }else if(X<Lburg[L-1].first+2){
      ans=burger(L-1,X-1,Lburg);
    }else if(X==Lburg[L-1].first+2){
      ans=Lburg[L-1].second+1;
    }else if(X<2*Lburg[L-1].first+3){
      ans=Lburg[L-1].second+1+burger(L-1,X-Lburg[L-1].first-2,Lburg);
    }else if(X==2*Lburg[L-1].first+3){
      ans=2*Lburg[L-1].second+1;
    }
  }
  return ans;
}

int main(){
    ll N,X;
    cin >> N >>X;
    pair<ll,ll> Lburg[N+1];
    Lburg[0].first=1;
    Lburg[0].second=1;
    ll i;
    for(i=1;i<=N;i++){
      Lburg[i].first=2*Lburg[i-1].first+3;
      Lburg[i].second=2*Lburg[i-1].second+1;
    }
    cout << burger(N,X,Lburg);
    return 0;
}
