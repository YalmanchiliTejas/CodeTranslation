#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define rep(i,n) for(int i=0; i<n; i++)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてから使う
#define INF 2147483647
#define LLINF 9223372036854775807LL

int main() {
  int n; cin >> n;
  const ll MOD = 1'000'000'007;
  vector<ll>A(n);
  ll sum = 0;
  rep(i,n){
    cin >> A[i];
    sum += A[i];
  }
  ll ans = 0;
  rep(i,n){
    sum -= A[i];
    ll tmp = sum%MOD;
    tmp = (tmp*A[i])%MOD;
    ans = (ans+tmp)%MOD;
  }
  cout << ans << endl;
}

