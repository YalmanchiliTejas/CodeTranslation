#include <bits/stdc++.h>
using namespace std;

#define int long long
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
const int INF = 1e9, MOD = INF + 7;

/////////////////////////////////////////////////////////////////////

const int N = 3e3 + 20;

int a[N], dp[N][N][2];

int32_t main(){

    sync;

    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int l = n - 1; l >= 0; l--) for(int r = l; r < n; r++) {
    	if (a[l] + dp[l + 1][r][1] < a[r] + dp[l][r - 1][1]) dp[l][r][0] = a[r] + dp[l][r - 1][1], dp[l][r][1] = dp[l][r - 1][0];
    	else dp[l][r][0] = a[l] + dp[l + 1][r][1], dp[l][r][1] = dp[l + 1][r][0];
    }
    cout << dp[0][n - 1][0] - dp[0][n - 1][1] << endl;

    return 0;
}