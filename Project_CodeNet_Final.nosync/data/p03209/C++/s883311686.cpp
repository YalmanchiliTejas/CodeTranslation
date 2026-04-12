#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int long long int
#define pb push_back
#define fi first
#define se second
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define IO ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
const int mod = 1e9 + 7;
const int mod1 = 998244353;
typedef long double f80;
#ifndef LOCAL
#define endl '\n'
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
const int N = 55;
int tot[N], pat[N];
int solve(int n, int &k){
    if(tot[n] <= k){
        k -= tot[n];
        return pat[n];
    }
    int ans = 0;
    if(k)
        k--;
    if(k)
        ans += solve(n - 1, k);
    if(k)
        ans++, k--;
    if(k)
        ans += solve(n - 1, k);
    return ans;
}
void solve(){
    int n, k;
    cin >> n >> k;
    tot[0] = 1, pat[0] = 1;
    fr(i, 1, n){
        tot[i] = 2 * tot[i - 1] + 3;
        pat[i] = 2 * pat[i - 1] + 1;
    }
    cout << solve(n, k) << endl;
}
signed main()
{
    IO;
    #ifdef LOCAL
        freopen("inp.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif
    clock_t clk = clock();
    int t = 1;
    // cin >> t;
    fr(i, 1, t){
        solve();
    }
    cerr << endl << setprecision(10) << fixed << (double)(clock() - clk) / CLOCKS_PER_SEC;
    return 0;
};