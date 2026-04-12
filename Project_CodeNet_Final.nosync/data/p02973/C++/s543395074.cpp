#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef set<int> si;
typedef map<string, int> msi;
typedef greater<int> gt;
typedef priority_queue<int, vector<int>, gt> minq;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  int n;cin>>n;
  vi a(n);
  rep(i,n) cin>>a[i];
  vi dp(n, -1);
  rep(i,n) {
    auto it = lower_bound(dp.begin(), dp.end(), a[i]);
    int idx = it - dp.begin();
    dp[idx-1] = a[i];
  }
  int ans = 0;
  rep(i,n) {
    if (dp[i] != -1) ans++;
  }
  cout << ans << endl;
  return 0;
}