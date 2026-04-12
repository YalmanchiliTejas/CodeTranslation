#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> a(n), sum(n+1);
  rep(i,n){
    cin >> a[i];
    sum[i] += a[i];
    sum[i+1] += sum[i];
    sum[i+1] %= MOD;
  }
  ll ans = 0;
  rep(i,n-1){
    ans += sum[i]*a[i+1];
    ans %= MOD;
  }
  cout << ans;
  cout << "\n";
  return 0;
}
