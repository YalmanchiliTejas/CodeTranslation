#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<endl;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }



int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  rep(i, n) {
    cin >> a[i];
    if(i!=0) sum += a[i];
    sum %= MOD;
  }
  ll ans = 0;
  rep(i, n-1) { 
    ans += (a[i] * sum)%MOD;
    ans %= MOD;
    sum -= a[i + 1];
    if (sum < 0) sum += MOD;
  }
  cout << ans%MOD << endl;
  return 0;
}