#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)

typedef long long ll;

const int Inf = 1e9;
const double EPS = 1e-9;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int bitCount(long bits) {
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string ans = "";
    int cnt[n][26];
    rep (i, n) {
      rep (j, 26) {
        cnt[i][j] = 0;
      }
    }
    rep (i, n) {
      string s;
      cin >> s;
      rep (j, s.size()) {
        cnt[i][s[j] - 'a']++;
      }
    }
    rep (j, 26) {
      int tmp = Inf;
      rep (i, n) {
        tmp = min(tmp, cnt[i][j]);
      }
      rep (i, tmp) {
        ans += 'a' + j;
      }
    }
    cout << ans << endl;

    return 0;
}
