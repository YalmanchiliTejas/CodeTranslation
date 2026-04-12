#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long i64;
typedef vector<int> vi;
typedef vector<i64> vi64;
typedef vector<vi> vvi;
typedef vector<vi64> vvi64;
typedef double ld;

bool check (string s, string ans) {

    int N = s.size();
    forn(i, s.size()) {
        char h;

        if (ans[i % N] == 'S') {
            if (ans[(i - 1 + N) % N] == ans[(i + 1) % N]) {
                h = 'o';
            } else {
                h = 'x';
            }
        }

        if (ans[i % N] == 'W') {
            if (ans[(i - 1 + N) % N] == ans[(i + 1) % N]) {
                h = 'x';
            } else {
                h = 'o';
            }
        }

        if (h != s[i]) return false;
    }

    return true;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int N;
    string s;
    cin >> N >> s;

    string ans = "SS";

    fore(i, 1, N - 2) {
        if (s[i] == 'o' and ans[i] == 'S') {
            ans += ans[i - 1];
        } else if (s[i] == 'o' and ans[i] == 'W') {
            if (ans[i -1] == 'S') ans += 'W';
            else ans += 'S';
        }
        if (s[i] == 'x' and ans[i] == 'S') {
            if (ans[i - 1] == 'S') ans += 'W';
            else ans += 'S';
        } else if (s[i] == 'x' and ans[i] == 'W') {
            ans += ans[i - 1];
        }
    }

    if (check(s, ans)) {
        cout << ans << endl;
        return 0;
    }

    ans = "SW";

    fore(i, 1, N - 2) {
        if (s[i] == 'o' and ans[i] == 'S') {
            ans += ans[i - 1];
        } else if (s[i] == 'o' and ans[i] == 'W') {
            if (ans[i -1] == 'S') ans += 'W';
            else ans += 'S';
        }
        if (s[i] == 'x' and ans[i] == 'S') {
            if (ans[i - 1] == 'S') ans += 'W';
            else ans += 'S';
        } else if (s[i] == 'x' and ans[i] == 'W') {
            ans += ans[i - 1];
        }
    }

    if (check(s, ans)) {
        cout << ans << endl;
        return 0;
    }

    ans = "WS";

    fore(i, 1, N - 2) {
        if (s[i] == 'o' and ans[i] == 'S') {
            ans += ans[i - 1];
        } else if (s[i] == 'o' and ans[i] == 'W') {
            if (ans[i -1] == 'S') ans += 'W';
            else ans += 'S';
        }
        if (s[i] == 'x' and ans[i] == 'S') {
            if (ans[i - 1] == 'S') ans += 'W';
            else ans += 'S';
        } else if (s[i] == 'x' and ans[i] == 'W') {
            ans += ans[i - 1];
        }
    }

    if (check(s, ans)) {
        cout << ans << endl;
        return 0;
    }

    ans = "WW";

    fore(i, 1, N - 2) {
        if (s[i] == 'o' and ans[i] == 'S') {
            ans += ans[i - 1];
        } else if (s[i] == 'o' and ans[i] == 'W') {
            if (ans[i -1] == 'S') ans += 'W';
            else ans += 'S';
        }
        if (s[i] == 'x' and ans[i] == 'S') {
            if (ans[i - 1] == 'S') ans += 'W';
            else ans += 'S';
        } else if (s[i] == 'x' and ans[i] == 'W') {
            ans += ans[i - 1];
        }
    }

    if (check(s, ans)) {
        cout << ans << endl;
        return 0;
    }

    cout << -1 << endl;

    return 0;
}