#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<ll> >;

const ll INF = 1e18;
const ll MOD = 1000000007;
const ll MX = 0; //最大値

#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define PB push_back
#define F first
#define S second

int main(){
    ll n; cin >> n;
    vector<ll> A(n);

    ll ans = 0, res = 0;
    rep(i, n) {
        cin >> A[i];
        res += A[i];
    }

    
    rep(i, n){
        res -= A[i];
        ll tmp = res % MOD;
        ans += tmp * A[i];
        ans %= MOD;
    }
    
    cout << ans << endl;
    return 0;
}