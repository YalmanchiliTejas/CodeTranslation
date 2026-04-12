#include <bits/stdc++.h>
using namespace std;

#define fa(x,v) for(auto x:v)
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define spc " "
#define endl '\n'
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define len(s) (ll)int(s.length())
#define sz(v) (ll)int(v.size())
#define MOD 1000000007

void Fast_IO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef rsd511
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    #ifndef rsd511
    #define trace(...) {}
    #define cotra(...) {}
    #endif
} 

// Code Here

int main()
{
    Fast_IO();
    ll n; cin >> n;
    ll a[n]; f(i,0,n-1) cin >> a[i];
    ll suff[n]; f(i,0,n-1) suff[i] = a[i];
    rf(i,n-2,0) suff[i] += suff[i+1];
    f(i,0,n-1) a[i] %= MOD, suff[i] %= MOD;
    ll ans = 0;
    f(i,0,n-2) {
    	ans += (a[i] * suff[i+1]) % MOD;
    	ans %= MOD;
    }
    cout << ans;
    return 0;
}