#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ff first
#define ss second
#define pb push_back
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int mod = 1e9 + 7;
const int cmod = 998244353;
const int N = 1e5 + 5;
const int inf = 1e16 + 2;


void solve(int Case) {
    int n ;
    cin >> n ;
    int a[n] , p[n] , ans = 0;
    for(int i = 0 ; i < n ; i ++){
        cin >> a[i] ;
        p[i] = a[i];
        if(i != 0) p[i] += p[i - 1];
    }
    for(int i = 0 ; i < n ; i ++) {
        int sum = p[n - 1];
        sum -= p[i];
        sum %= mod ;
        ans = (ans + (sum * a[i]) % mod + mod) % mod;
    }
    cout << ans << '\n';
}
/*
 */

int32_t main()
{
    fastio
    int testcase = 1;
    //cin >> testcase;
    int Case = 1;
    while(testcase --) {
        solve(Case ++);
    }
    return 0;
}
