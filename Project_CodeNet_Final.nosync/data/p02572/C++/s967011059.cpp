#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vll = vector<ll>;
using pii = pair<int, int>;

const ll mod = 1e9+7;
int main(){
  ll N; cin >>N;
  vll A(N);
  rep(i,N) cin >> A[i] ;
  ll ans = 0;
  ll temp = 0;
  rep2(i,1,N) temp += A[i];
  temp %= mod;
  ans += temp*A[0];
  ans %= mod;
  rep2(i,1,N-1){
    temp -= A[i];
    if(temp<0) temp += mod;
    ans += (A[i]*temp)%mod;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
