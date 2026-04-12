#pragma GCC optimize("O3")

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<pii>
#define read(FILE)  freopen(FILE, "r", stdin);
#define out(FILE) freopen(FILE, "w", stdout);
#define clr(x, y) memset(x,y,sizeof(x));
#define IO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define all(x) x.begin(),x.end()
#define rep(i, m, n) for(int i=m ; i<n ; i++)
#define forr(i, m, n) for(ll i=m ; i<=n ; i++)
#define endl '\n'
#define pb push_back
#define re return
const int N = 2e5 + 5;
const ll OO = 1e15;
using namespace std;
ll n;
ll arr[N];
ll dp[N][3];

ll solve(ll i, ll c) {
    if (i > n) {
        re c ? -OO : 0;
    }
    ll &ret = dp[i][c];
    if (~ret) re ret;
    ret = -OO;
    if (c) {
        ret = max(ret, solve(i + 1, c - 1));
    }
    ret = max(ret, arr[i] + solve(i + 2, c));
    re ret;
}

int main() {
    cin >> n;
    rep(i, 0, n) {
        cin >> arr[i];
    }
    /*rep(i, 0, N) {
        rep(j, 0, 3) {
            dp[i][j] = OO;
        }
    }*/
    clr(dp, -1);
    cout << solve(0, (n & 1) + 1);

}