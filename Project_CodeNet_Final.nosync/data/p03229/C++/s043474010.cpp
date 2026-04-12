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

  ll N; cin>>N;
  vector<ll> A(N); rep(i,N) cin>>A[i];
  
  sort(A.begin(),A.end());
  ll ans=0;
  if(N%2==0){
    for(int i=N/2;i<N;i++) ans+=(i==N/2?1:2)*A[i];
    rep(i,N/2) ans-=(i==N/2-1?1:2)*A[i];
    cout<<ans<<endl;
  }
  else{
    for(int i=(N+1)/2;i<N;i++) ans+=2*A[i];
    rep(i,(N+1)/2) ans-=((N+1)/2-2<=i?1:2)*A[i];
    //cout<<ans<<endl;
    
    ll sans=0;
    for(int i=N/2;i<N;i++) sans+=(i<=N/2+1?1:2)*A[i];
    rep(i,N/2) sans-=2*A[i];
    
    chmax(ans,sans);
    cout<<ans<<endl;
  }
  
  return 0;
}