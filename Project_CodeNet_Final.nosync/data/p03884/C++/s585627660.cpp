//#ifdef DEBUG
//#define _GLIBCXX_DEBUG
//#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937 rnd(228);
ll g(ll x) {
    ll c = 1;
    for (int i = 1; i <= 7; i++) c *= x;
    return c;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    ll k;
    cin >> k;
    string p = "FESTIVAL";
    string cur;
    ll t = 1;
    while (g(t + 1) <= k) t++;
    for (int x = 1; x <= 7; x++) {
        for (int c = 1; c <= 300; c++) {
            cur += p[x];
        }
    }
    for (int c = 0; c <= 1500; c++) {
        int x = rnd() % 7 + 1;
        cur += p[x];
    }
    for (int c = 0; c <= 13; c++) {
        cur += p[c % 7 + 1];
    }
    vector < int > before(cur.size());
    vector < vector < ll > > calc(cur.size() + 1, vector<ll>(8, 0));
    calc[cur.size()][7] = 1;
    for (int i = cur.size() - 1; i >= 0; i--) {
        calc[i] = calc[i + 1];
        for (int j = 1; j <= 7; j++) {
            if (cur[i] == p[j]) {
                calc[i][j - 1] += calc[i][j];
                calc[i][j - 1] = min(calc[i][j - 1], k + 1);
            }
        }
    }
    for (int where = 0; where < cur.size(); where++) {
        if (k == 0) break;
        before[where] = k / calc[where][0];
        k %= calc[where][0];
    }
    string ans;
    for (int i = 0; i < cur.size(); i++) {
        ans += string(before[i], p[0]);
        ans += cur[i];
    }
    assert(k == 0);
    assert(ans.size() <= 5000);
    cout << ans << endl;
    return 0;
} 