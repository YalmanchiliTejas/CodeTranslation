#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define rREP(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;

ll maisus[51];
ll pmaisu[51];


ll func(int n, ll x)
{
    if (n==0) return 1;
    if (x==0) return 0;
    if (x<=maisus[n-1])
    {
        return func(n-1, x-1);
    }
    else if (x == maisus[n-1]+1)
    {
        return pmaisu[n-1]+1;
    }
    else
    {
        // cout <<"n: " << n<< endl;
        // cout <<"x: " << x<< endl;

        return pmaisu[n-1]+1+func(n-1, x-maisus[n-1]-2);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    maisus[0] = 1;
    REP(i,1,51)
    {
        maisus[i] = maisus[i-1] * 2 + 3;
    }
    pmaisu[0] = 1;
    REP(i,1,51)
    {
        pmaisu[i] = 2 * pmaisu[i-1] + 1;
    }
    int n;
    ll x;
    cin >> n >> x;

    ll ans = func(n,x-1);
    cout << ans << endl;
}
