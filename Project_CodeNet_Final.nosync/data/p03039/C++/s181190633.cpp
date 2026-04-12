#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
ll const mod = 1e9+7;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

const int MAX_N = 200010;
ll fact[MAX_N],fact_inv[MAX_N],inv[MAX_N];

ll pow_mod(ll a,ll b) {
    ll ret;
    if (b < 0) ret = pow_mod(a,mod+b-1);
    else if (b == 0) ret = 1;
    else if (b == 1) ret = a;
    else {
        ll c = pow_mod(a,b/2);
        if (b%2) ret = (c*c)%mod*a%mod;
        else ret = c*c%mod;
    }
    return ret;
}

void create_table(int x) {
    fact[0] = 1;fact[1] = 1;
    for (int i = 2;i <= x;++i) fact[i] = fact[i-1]*i%mod;
    fact_inv[x] = pow_mod(fact[x],-1);
    for (int i = x;i > 0;--i) fact_inv[i-1] = fact_inv[i]*i%mod;
    for (int i = 1;i <= x;++i) inv[i] = fact_inv[i]*fact[i-1]%mod;
}

ll combi(ll a, ll b) {
    return fact[a]*fact_inv[b]%mod*fact_inv[a-b]%mod;
}

int main() {
    create_table(200000);
    ll n,m,k;
    cin >> n >> m >> k;
    vector<int> sumx(n+1,0),sumy(m+1,0);
    ll ans = 0;
    for (int i = 0;i < n;++i) {
        (ans += m*m%mod*combi(n*m-2,k-2)%mod*(n-i)%mod*(n-i-1)%mod*pow_mod(2,-1)) %= mod;
    }
    for (int i = 0;i < m;++i) {
        (ans += n*n%mod*combi(n*m-2,k-2)%mod*(m-i)%mod*(m-i-1)%mod*pow_mod(2,-1)) %= mod;
    }
    cout << ans << endl;
}