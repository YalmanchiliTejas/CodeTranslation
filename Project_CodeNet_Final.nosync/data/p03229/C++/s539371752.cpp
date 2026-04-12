#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  ll N;
  cin>>N;
  vector<ll> v(N);
  for(ll i = 0; i < N; i++) cin>>v[i];
  sort(v.begin(),v.end());
  ll ans = 0LL;
  if(N%2==0){
    for(ll i = 0; i < N/2; i++){
      if(i==N/2-1) ans-=v[i];
      else ans-=2LL*v[i];
    }
    for(ll i = N/2; i < N; i++){
      if(i==N/2) ans+=v[i];
      else ans+=2LL*v[i];
    }
  }
  if(N%2==1){
    ll ansa = 0LL, ansb = 0LL;
    for(ll i = 0; i < N;i++){
      if(i<N/2) ansa-=2LL*v[i];
      else if(i==N/2||i==N/2+1) ansa += v[i];
      else ansa+=2LL*v[i];
    }
    for(ll i = 0; i < N; i++){
      if(i==N/2-1||i==N/2) ansb-=v[i];
      else if(i<N/2+1) ansb-=2LL*v[i];
      else ansb+=2LL*v[i];
    }
    ans=max(ansa,ansb);
  }
  cout<<ans<<endl;
}