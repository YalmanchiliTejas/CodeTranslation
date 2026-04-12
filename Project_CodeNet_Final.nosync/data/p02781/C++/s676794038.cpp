#include <bits/stdc++.h>

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, a, b) for (int i = (int)(a); i >= (int)b; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)
#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

string s;
i64 k, ans = 0;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("in", "r", stdin);
#endif

	cin >> s;
    i64 len = i64(s.size());
    i64 n1 = -1, n2 = -1, n3 = -1, p2 = -1, p3 = -1;
    n1 = s[0] - '0';
    for (int i = 1; i < len; ++i) {
        if (s[i] != '0') {
            n2 = s[i] - '0';
            p2 = i + 1;
            break;
        }
    }
    if (p2 != -1) {
        for (int i = p2; i < len; ++i) {
            if (s[i] != '0') {
                n3 = s[i] - '0';
                p3 = i + 1;
                break;
            }
        }
    }
	cin >> k;
	if (k > len) {
        cout << 0 << '\n';
        return 0;
	}
	i64 tot = 0;
	i64 no = 0;
	if (k == 1) tot = len * 9;
	if (k == 2) {
        tot = len * (len - 1) / 2 * 9 * 9;
	}
	if (k == 3) {
       tot = len * (len - 1) * (len - 2) / 6 * 9 * 9 * 9;
	}
	if (k == 1) {
        no += (9 - n1);
	}
	if (k == 2) {
        no += (9 - n1) * (len - 1) * 9;
        if (n2 == -1) {
            no += (len - 1) * 9; // ok
        } else {
            no += (p2 - 2) * 9;//ok
            no += (9 - n2); // ok
        }
	}
	if (k == 3) {
        no += (9 - n1) * (len - 1) * (len - 2) / 2 * 9 * 9;
        if (n3 == -1) {
            if (n2 == -1) no += (len - 1) * (len - 2) / 2 * 9 * 9; // !!!!!fuck!!!
            else {
                no += ((p2 - 2) * 9 + (9 - n2 + 1)) * (len - p2) * 9;
                if (p2 - 2 > 0) {
                    no += (p2 - 2) * (p2 - 3) / 2 * 9 * 9;
                    no += (9 - n2 + 1) * (p2 - 2) * 9;
                }
            }
        } else {
            no += ((p2 - 2) * 9 + (9 - n2)) * ((len - p2) * 9) + ((p3 - p2 - 1) * 9 + (9 - n3));
        }
	}
	cout << (tot - no) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
