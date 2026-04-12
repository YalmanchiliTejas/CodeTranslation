#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;

int n, m;
string s[10];

void no() { cout << "Impossible"; exit(0); }

int main() {
#ifdef LOCAL
//     freopen("a.in", "r", stdin);
#endif

    cin >> n >> m;
    forn(i, n) cin >> s[i];
    int x = 0, y = 0;
    if (s[0][0] != '#') no();
    s[0][0] = '.';
    while (x+1 != n || y+1 != m) {
        if (x+1 < n && s[x+1][y] == '#') {
            ++x;
        } else if (y+1 < m && s[x][y+1] == '#') {
            ++y;
        } else {
            no();
        }
        s[x][y] = '.';
    }
    forn(i, n) forn(j, m) if (s[i][j] == '#') no();
    cout << "Possible";


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
