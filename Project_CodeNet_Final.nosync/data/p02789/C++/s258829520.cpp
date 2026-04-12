#include <bits/stdc++.h>
#define maxn 200001
#define maxa 201
#define MOD 1000000007
#define INF 1000000000000000000
#define lim 20

using namespace std;

#define ll long long
#define pii pair<ll, ll>
#define piii pair<pii, ll>
#define ft first
#define sd second

void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

ll power(ll a, ll b){
    if(b == 0) return 1;
    ll r = power(a, b/2);
    r = (r*r)%MOD;
    if(b%2 == 1) r = (r*a)%MOD;
    return r;
}




void solve(){
    ll n, m;
    cin >> n  >> m;
    if(n == m) cout << "Yes\n";
    else cout << "No\n";

}

int main()
{
    fast();
    ll t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
