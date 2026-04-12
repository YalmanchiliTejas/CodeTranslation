#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define pb push_back
#define rep(i, a, n) for(int i = (a); i < (n); i++)
#define dep(i, a, n) for(int i = (a); i >= (n); i--)
#define mod (ll)(1e9+7)
#define int ll

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

int n;
map<char, int> mp[50];

signed main() {
  cin >> n;
  rep(i, 0, n) {
    string s;
    cin >> s;
    rep(j, 0, s.length()) {
      mp[i][s[j]]++;
    }
  }
  rep(i, 0, 26) {
    int mn = 1145141919;
    rep(j, 0, n) {
      mn = min(mn, mp[j][(char)('a' + i)]);
    }
    rep(j, 0, mn) {
      cout << (char)('a' + i);
    }
  }
  cout << endl;
}
