#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define pb push_back
#define sz(s) (int)s.size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define for1(i,n) for(int i=1;i<=(int)n;i++)
#define ford(i, b, a) for (int i = (int)(b); i >= a; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
const int N = (int)1e5+77;
const ll inf = (ll) 1e15+77;
const int mod = (int) 1e9 + 7;
const ld pi = acos(-1);

ll dp[3005][3005];
int main() {
    fast;
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    ford(L, n - 1, 0) {
        fore(R, L, n - 1) {
            if (L == R) dp[L][R] = a[L];
            else dp[L][R] = max(a[L] - dp[L + 1][R], a[R] - dp[L][R - 1]);
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}