/* Author : Aaryan Srivastava ^__^ */ 
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back   
#define sz(a) ((int)a.size())
using namespace std;
typedef long long ll ; 
const ll inf = 1e18 ;
const int mod = 1e9 + 7;
const int N = 3e5 + 5; 
const int SZ = 101;
ll po(ll x,ll y,ll p = mod) {ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}


void solve(){
    int n , k ;
    cin >> n >> k;
    ll ans = 0 ;
    if(!k){
        cout << 1LL * n * n ;
        return ;
    }
    for(int i = k + 1 ; i <= n ; ++i){
        int b = i ;
        if(b <= k){
            continue ;
        }
        int rem = (n % b) ;
        int cnt = n / b ;
        ans += (1LL * cnt * (b - k));
        if(rem) ans += (rem - min(k - 1 , rem));
        // cout << ans << ' ';
    }
    // ans = n * n - ans ;
    cout << ans ;
}

int main()
{
    ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int TC = 1, t = 0;
    // cin >> TC ;
    while(t++ < TC)
    {
        // cout << "Case #" << t << ": " ;
        solve();
        cout << "\n" ;
    }
    return 0;
}