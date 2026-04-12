#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i <= n; i++)
#define FORR(i, m, n) for(ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n)
#define MAX 100000
#define mod 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using graph = vector<vector<int>>;
using Grid = vector<vector<bool>>;

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, ans, sum;
    cin >> n;
    vll a(n, 0);
    ans = 0;
    sum = 0;
    REP(i, n){
        cin >> a[i];
        sum += a[i];
        sum %= mod;
    }

    REP(i, n){
        sum -= a[i];
        if (sum < 0) sum += mod;
 
        ans += a[i] * sum;
        ans %= mod;
    }

    cout << ans <<"\n";
	return 0;
}