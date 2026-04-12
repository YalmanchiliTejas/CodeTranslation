#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
#define all(vec) vec.begin(),vec.end()
using namespace std;

using ll=long long;

using vi=vector<int>;
using vll=vector<ll>;
using vvi=vector<vi>;
using vs=vector<string>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int N; cin >>N;
  vi A(N);
  vll B(N+1);
  int mod=pow(10,9)+7;
  rep(i,0,N) {
    cin >>A[i];
    B[i+1]=B[i]+A[i];
  }
  ll ans=0;
  rep(i,0,N) {
    ll sum=(B[N]-B[i+1])%mod;
    ans+=A[i]*sum;
    ans%=mod;
  }
  cout <<ans <<'\n';
  return 0;
}
