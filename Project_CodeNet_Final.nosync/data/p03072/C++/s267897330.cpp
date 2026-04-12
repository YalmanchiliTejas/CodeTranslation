#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define sync ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define endl "\n"
#define ends " "
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define debug(x) cerr << #x << ": " << x << endl
#define debugP(p) cerr << #p << ": {" << p.first << ", " << p.second << '}' << endl
#define debugV(v) cerr << #v << ": [ "; for(int __ = 0; __ < v.size(); __++) cerr << v[__] << ((__ != v.size() - 1) ? ", " : ends); cerr << ']' << endl
#define debugVP(v) cerr << #v << ": [ "; for(int ___ = 0; ___ < v.size(); ___++) cerr << '{' << v[___].first << ", " << v[___].second << '}' << ((___ != v.size() - 1) ? ", " : ends); cerr << ']' << endl
#define debugA(a, n) cerr << #a << ": [ "; for(int ____ = 0; ____ < n; ____++) cerr << a[____] << ((____ != n - 1) ? ", " : ends); cerr << ']' << endl
#define print(args...) fprintf (stderr, args)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
const int INF = 1e9, MOD = INF + 7 /* INF - 1755647 */;

/////////////////////////////////////////////////////////////////////

const int N = 3e5 + 20;

int32_t main() {

    sync;

    int n; cin >> n;
    int ans = 0, mx = 0;
    while(n--) {
        int x; cin >> x;
        if (x >= mx) ans++;
        mx = max(x, mx);
    }
    cout << ans << endl;

    return 0;
}
