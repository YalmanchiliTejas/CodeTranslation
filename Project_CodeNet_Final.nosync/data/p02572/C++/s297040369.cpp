#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using ll = long long;
#define ull unsigned ll
#define endl "\n"
#define vi vector<int>
#define vl vector<ll>
#define all(v) (v).begin(),(v).end()
#define mst(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define pll pair<ll, ll>
#define ppi pair<int, pii>
#define vpi vector<pii>
#define vpl vector<pll>
#define mt make_tuple
#define eb emplace_back
using namespace std;

const ll N = 2e5 + 5, mod = 1e9 + 7;
const ll inf = 1e18;

struct cmp{
    bool operator() (pii a, pii b){
        if(a.F == b.F) return a.S < b.S;
        return a.F > b.F;
    }
};

ll power(ll x, ll p){
    ll r = 1ll;
    x = x % mod;
    while(p > 0){
        if(p & 1) r = (r * x) % mod;
        p = p >> 1;
        x = (x * x) % mod;
    }
    return r;
}

void solve(){
    ll n;
    cin >> n;
    vl a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = 0, sum = 0;
    for(ll i = 0; i < n; i++){
        ans = (ans + (sum * a[i]) % mod) % mod;
        sum = (sum + a[i]) % mod;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //cout.tie(0);
    /*#ifndef ONLINE_JUDGE
        freopen("Input.txt", "r", stdin);
    #endif*/
    //freopen("running_on_fumes_chapter_1_input (1).txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    int t = 1, p;
    //cin >> t;
    for(p = 1; p <= t; p++){
        //cout << "Case #" << p << ": ";
        solve();
    }
    return 0;
}
