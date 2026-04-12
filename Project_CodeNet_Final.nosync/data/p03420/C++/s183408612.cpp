//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
//const ll MOD=998244353;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // cout << fixed << setprecision(15);

  ll N,K; cin>>N>>K;
  ll ans=0;
  for(int b=K+1;b<=N;b++){
    ll q=N/b; ans+=(b-K)*q;
    if(b*q+K<=N) ans+=N-(b*q+K)+1;
    if(K==0) ans--;
    //cout<<ans<<endl;
  }
  
  cout<<ans<<endl;
  
  return 0;
}