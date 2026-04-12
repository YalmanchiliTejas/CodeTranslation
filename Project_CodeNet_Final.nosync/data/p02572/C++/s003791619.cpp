#include<bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define ll long long
#define rep(i,n) for (int i = 0; i < (n); i++)

int main()
{
  int N;
  cin >> N;
  vector<ll> B(N+1,0);
  vector<ll> v(N);
  rep(i,N){
    cin >> v[i];
    B[i+1]=B[i]+v[i];
  }
  int MOD=1000000007;
  ll ans=0;
  for(int i=0;i<N;i++){
    ll sum=(B[N]-B[i+1])%MOD;
    ans+=(v[i]*sum)%MOD;
    ans%=MOD;
  }
	cout<<ans<< endl;
}
