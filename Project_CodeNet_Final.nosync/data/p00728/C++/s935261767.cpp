#include <bits/stdc++.h>
#define rep(i, n) for(int i=0;i<n;++i)
#define FOR(i, a, b) for(int i=a;i<b;++i)
#define RFOR(i, a, b) for (int i=a;i>=b;--i)
#define ll long long
#define all(a) a.begin(),a.end()
#define ull unsigned long long
#define pb(x) push_back(x)
#define dbg(x) cout<<#x<<" : "<<(x)<<endl;
using namespace std;
const int INF = 1500000000;
const double PI = 3.14159265359;
const int mod = 1000000000 + 7;

int n, s[1000];

void solve() {
  int res = 0, mins = 1000, maxs = 0;
  rep(i, n) {
    res += s[i];
    maxs = max(maxs, s[i]);
    mins = min(mins, s[i]);
  }
  res -= maxs;
  res -= mins;
  printf("%d\n", res / (n-2));
}

int main() {
  while(true) {
    scanf("%d", &n);
    if (!n) break;
    rep(i, n) scanf("%d", &s[i]);
    solve();
  }
  return 0;
}