#include <bits/stdc++.h>
using namespace std;


#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

ll mod = 1e9 + 7ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll inf = 1ll << 60;

ll n, m, k;
vector<ll> rem(201010); /// rem.at(i)はiの階乗i!をmodで割った余り
vector<ll> rinv(201010); /// rinv.at(i)は1/i!,つまり「i!にかけたら1になる数」をmodで割った余り
vector<ll> inv(201010); /// inv.at(i)は1/iをmodで割った余り

int gcc(int n, int m) {
    int a = max({n, m});
    int b = min({n, m});
    if(b == 0) return a;
    int c;
    while(a % b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return b;
}

///前処理
void prev(){
    rem.at(1) = 1ll;
    rem.at(0) = 1ll;
    inv.at(1) = 1ll;
    inv.at(0) = 0ll;
    rinv.at(0) = 1ll;
    rinv.at(1) = 1ll;
    rp(i, 2, n*m+6){
        rem.at(i) = rem.at(i-1) * i % mod;
        inv.at(i) = mod - (inv.at(mod % i) * (mod / i)) % mod;
        rinv.at(i) = (rinv.at(i-1) * inv.at(i)) % mod;
    }
}

int main() {
    scanf("%lld%lld%lld", &n, &m, &k);
    prev();
    ll cmb = (rem.at(n * m - 2) * rinv.at(k - 2)%mod * rinv.at(n * m - k)%mod) % mod;
    printf("%lld\n", (((m*m%mod*m%mod - m)*n*n%mod + (n*n%mod*n%mod - n)*m*m%mod) * inv.at(6)%mod * cmb%mod));
    return 0;
    
}
