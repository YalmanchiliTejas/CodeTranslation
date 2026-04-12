#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF 1000000000000000
#define MOD 1000000007

int main(){
  ll N;
  cin>>N;
  vector<ll> a(N);
  for(ll i=0;i<N;i++){
    cin>>a.at(i);
  }

  bool flag=true;
  for(ll i=0;i<N;i++){
    if(a.at(i)>=N){
      flag=false;
    }
  }
  if(flag){
    cout<<0<<endl;
    return 0;
  }
  ll ans=0;
  while(true){
    ll sum=0;
    vector<ll> count(N,0);
    for(ll i=0;i<N;i++){
      if(a.at(i)>=N){
        count.at(i)=(a.at(i)-N)/N+1;
        sum+=count.at(i);
        ans+=count.at(i);
        a.at(i)-=count.at(i)*N;
      }
    }
    for(ll i=0;i<N;i++){
      a.at(i)+=sum-count.at(i);
    }
    bool flag=true;
    for(ll i=0;i<N;i++){
      if(a.at(i)>=N){
        flag=false;
      }
    }
    if(flag){
      cout<<ans<<endl;
      break;
    }
  }
}
