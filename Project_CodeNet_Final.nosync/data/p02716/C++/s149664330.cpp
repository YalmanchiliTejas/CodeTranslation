#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(long long i = 0;i < n;i++)
#define repr(i, n) for(int i = n;i >= 0;i--)
#define Sort(v, n) sort(v, v+n);
#define VSort(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define INF 999999999
#define cY cout<<"Yes";
#define cN cout<<"No";
#define cA(a) cout<<a;
const ll MOD = 1000000007;



int main() {
    ll n,ans = 0;
    cin >> n;
    ll a[n];
    rep(i,n) cin >> a[i];
    //assert(n%2 == 0);
    if(n % 2 == 0) {
        ll dp[n];
        dp[0] = a[0];
        dp[1] = a[1];
        for(int i = 2;i<n;i++) {
            if(i % 2 == 0) {
                dp[i] = dp[i-2] + a[i];
            } else {
                dp[i] = max(dp[i-3],dp[i-2]) + a[i];
            }
        }
        ans = max(dp[n-1],dp[n-2]);
    } else {
        vector<ll> l(n/2),m(n/2),r(n/2);
        l[0] = a[0];
        m[0] = a[1];
        r[0] = a[2];
        for(int i = 1;i<n/2;i++) {
            l[i] = l[i-1] +a[2*i];
            m[i] = max(l[i-1],m[i-1]) + a[2*i+1] ;
            r[i] = max(l[i-1],max(m[i-1],r[i-1])) +a[i*2+2];
        }
        ans = max(l[n/2-1],max(m[n/2-1],r[n/2-1]));
    }
    cout << ans;
}