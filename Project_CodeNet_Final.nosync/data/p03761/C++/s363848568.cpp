/**
 * @author: Mackenzie
**/
#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6;
int main() {
#ifdef LOCALe
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n;
    cin >> n;
    vector<string> s(n);
    forn(i, n) cin >> s[i];
    vector<map<char, int>> v;
    forn(i, n) {
        map<char, int> cur;
        forn(j, sz(s[i])) {
            cur[s[i][j]]++;
        }
        v.pb(cur);
    }
    map<char, int> ans;
    for (char i = 'a'; i <= 'z'; i++) {
        ans[i] = 1e9;
    }
    forn(i, n) {
        for (char j = 'a'; j <= 'z'; j++) {
            ans[j] = min(ans[j], v[i][j]);
        }
    }
    for (auto x : ans) {
        forn(i, x.S) cout << x.F;
    }
    cout << endl;

    return 0;
}