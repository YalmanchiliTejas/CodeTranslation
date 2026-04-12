#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()
const ll mod = 1e9+7;

int main(){
  ll N;cin>>N;
  vll A(N);rep(i,N)cin>>A[i];
  vll acum(N+1,0);
  rep(i,N) acum[i+1]=acum[i]+A[i];
  ll ans = 0;
  rep(i,N){
    ans += A[i] * ((acum[N] - acum[i+1]) % mod);
    ans %= mod;
  }
  cout << ans << endl;
}