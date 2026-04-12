#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, int> i_i;
ll INF = 1e9+10;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
vector<pair<ll, ll> > pairs;

ll n, mod = 998244353;
const ll MAX = 1e7 + 1;
vector<ll> v(MAX);

ll inv[MAX];

void init() {
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
    }
}

int main()
{
    ll N;
    cin >> N;
    init();
    
    ll sub = 0;
    ll beki = 1, nCk = 1;
    for (int i = N; i >= N/2+1; i--){
        (sub += beki * nCk)%=mod; 
        (nCk *= i) %= mod;
        (nCk *= inv[N + 1 - i]) %= mod;
        (beki *= 2) %= mod;
    }
    (sub *= 2) %= mod;
    
    
    ll ans = 1;
    rep(i, N){
        (ans *= 3) %= mod;
    }
    (ans += mod - sub) %= mod;
    cout << ans << endl;
    return 0;    
}
