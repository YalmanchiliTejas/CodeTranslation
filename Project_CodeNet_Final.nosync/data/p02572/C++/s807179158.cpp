#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define clr(a) memset(a, 0, sizeof(a))
#define sz(x) x.size()
#define printarray(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout<<*it<<" "; cout<<endl;
#define rep(n) for (ll i = 0; i < n; i++)
#define repc(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, x, y) for (int i = x; i < y; i++)
#define DEC(i, x, y) for (int i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define alla(a, n) a, a + n
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b)/gcd(a, b)
#define int long long int
#define ull unsigned long long

using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

int fastexpo(int b, int exp){
    if(exp == 0) return 1;
    if(exp == 1) return b;
    int ans = (fastexpo(b,exp/2) % MOD);
    ans *= ans;
    ans %= MOD;
    if(exp % 2 == 1){
        ans *= b;
    }
    ans %= MOD;
    return ans;
}



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n+2];
    for(int i= 0;i<n;i++){
        cin>>a[i];
    }
    int pref[n+2];
    pref[0] = 1;
    int fin = 0;
    for(int i= 1;i<=n;i++){
        pref[i] = pref[i-1]%MOD;
        pref[i] += (a[i-1]%MOD);
        pref[i] %= MOD;
        fin = pref[i];
    }
    int ans= 0;
    for(int i= 0;i<n;i++){
        ans += ((a[i]%MOD) * (fin-pref[i+1]+MOD)%MOD)%MOD;
        ans %= MOD;
    }
    cout<<ans<<endl;
    return 0;
}



