#include <bits/stdc++.h>
using namespace std;

#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(c) c.begin(), c.end()
#define SZ(c) (int) c.size()
#define DBG1(x) cout<<#x<<" = "<<x<<"\n"
#if USE_CP_REDIR
#define CP \
    freopen("input.txt","r", stdin); \
    freopen("output.txt","w", stdout);
#endif

using ll = long long;
const ll MOD = 1'000'000'007;

ll add(ll a, ll b){
    return (a % MOD + b % MOD) % MOD;
}
ll mult(ll a, ll b){
    return (a % MOD * b % MOD) % MOD;
}


int main()
{
ios::sync_with_stdio(false);
#ifdef CP
    CP;
#endif
    int n;
    cin >> n;
    vector<int> a(n), suff(n+1);
    REP(i, 0, n) cin >> a[i];
    suff[n] = 0;
    for (int i = n-1; i >= 0; i--){
        suff[i] = add(suff[i+1], a[i]);
    }
    ll ans = 0;
    REP(i, 0, n){
        ans = add(ans, mult(a[i], suff[i+1]));
    }
    cout << ans << endl;
}