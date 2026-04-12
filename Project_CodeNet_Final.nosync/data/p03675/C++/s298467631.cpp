#include <bits/stdc++.h>
using namespace std;

#define int long long

#define inf 1000000007LL
#define mod 1000000007LL

#define rep(i, n) for(int i = 0; i < (n); i++)
#define trep(i, n) for(int i = 0; i <= (n); i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define mfor(i, s, t) for(int i = (s); i < (t); i++)
#define tfor(i, s, t) for(int i = (s); i <= (t); i++)
#define rfor(i, s, t) for(int i = (t) - 1; i >= (s); i--)

int ans[334334];

signed main() {
  int n;
  cin >> n;
  rep(i, n) {
    int w;
    cin >> w;
    if(i % 2 == (n - 1) % 2) {
      ans[(n + 1) / 2 - 1 - i / 2] = w;
    }
    else {
      ans[(n + 1) / 2 + i / 2] = w;
    }
  }
  rep(i, n) {
    cout << ans[i];
    if(i < n - 1) {
      cout << " ";
    }
    else {
      cout << endl;
    }
  }
}
