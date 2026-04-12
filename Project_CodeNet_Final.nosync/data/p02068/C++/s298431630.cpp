#include<bits/stdc++.h>
using namespace std;
using Int = long long;
using ll = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b)a=b;};
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b)a=b;};

template<typename T> void drop(T x){cout<<x<<endl;exit(0);};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  ll N;
  cin>>N;
  vector<ll> A(N);
  for(auto &I:A){cin>>I;}
  map<ll,ll> S;
  for(auto &I:A){
    ll num=I;
    for(ll i=2;i*i<=I;i++){
      if(I%i==0){
        S[i]+=num;
        while(I%i==0){I/=i;}
      }
    }
    if(I!=1){S[I]+=num;}
  }
  ll mx=0;
  for(auto &I:S){mx=max(mx,I.second);}
  cout<<mx<<endl;

  return 0;
}

