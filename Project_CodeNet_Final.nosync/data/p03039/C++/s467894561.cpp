#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MIN(a) *min_element(all(a))
#define MAX(a) *max_element(all(a))
#define SUM(a, b) accumulate(all(a), b)
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define RREP(i, n) for(int (i)=(n)-1; (i)>=0; (i)--)
#define FOR(i, m, n) for(int (i)=(m); (i)<(n); i++)
#define FORR(i, m, n) for(int (i)=(n)-1; (i)>=(m); i--)
#define ios() cin.tie(0), ios::sync_with_stdio(false)
#define debug(x) cerr << #x << " = " << x << endl
//#define int long long

typedef long long ll;
typedef unsigned long long ull;
//ll const MOD = 998244353;
ll const MOD = 1e9+7;
ll const INF = 1e18;

template<typename T> int size(const T& a){return (int)a.size();}
template<typename T> T Div(T a, T b){return (a + b - 1) / b;}
template<typename T> bool chmin(T& a, const T& b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, const T& b){if(a < b){a = b; return true;} return false;}

class Combination{
public:
    ll N;
    ll mod;
    vector<ll> fact;

    Combination(ll n, ll m) : N(n), mod(m), fact(n+1){
        fact.at(0) = 1;
        for(ll i=1; i<=N; i++){
            fact.at(i) = i * fact.at(i-1) % mod;
        }
    }

    ll POW(ll a, ll b){
        ll res = 1;
        while(b > 0){
            if(b & 1){
                res = res * a % mod;
            }
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    ll combin(ll n, ll k){
        if(n < 0 || k < 0 || n < k){
            return 1;
        }
        return fact.at(n) * POW(fact.at(k) * fact.at(n-k) % mod, mod - 2) % mod;
    }
};

signed main(){
    ll n, m, k;
    cin >> n >> m >> k;

    Combination C(n*m, MOD);

    ll ans = 0;

    for(ll i=1; i<n; i++){
        ll d = i * m * m * (n - i) % MOD;
        d *= C.combin(n*m-2, k-2);
        ans = (ans + d) % MOD;
    }

    for(ll i=1; i<m; i++){
        ll d = i * n * n * (m - i) % MOD;
        d *= C.combin(n*m-2, k-2);
        ans = (ans + d) % MOD;
    }

    cout << ans << endl;

    return 0;
}
