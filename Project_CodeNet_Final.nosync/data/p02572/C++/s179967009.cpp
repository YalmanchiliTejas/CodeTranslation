#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;
const int inf = (1<<29);

int main() {

    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> sum(n, 0);
    REP(i, n) {
        cin >> a[i];
    }
    sum[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--) {
        sum[i] = (sum[i+1] + a[i]) % MOD;
    }

    ll res = 0;
    for(int i = 0; i < n-1; i++) {
        res += (a[i] * sum[i+1])%MOD;
        cerr << a[i] << " " << sum[i+1] << endl;
    }

    cout << res % MOD << endl;
    


    return 0;
}