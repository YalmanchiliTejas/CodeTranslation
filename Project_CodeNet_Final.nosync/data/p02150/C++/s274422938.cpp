#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long LL;
const int INF = 999999999;
const LL mod = 1000000007;

LL modpow(LL a, LL b, LL p){
    if(b==0) return 1;
    else if(b%2==0){
        LL d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a*modpow(a, b-1, p)) % p;
    }
}

LL dv(LL x, LL a){
    return (x*modpow(a, mod-2, mod)) % mod;
}

int main(){
    LL a,b,x;
    cin >> a >> b >> x;
    LL ans = 0;
    if(x < a){
        cout << x%mod << endl;
        return 0;
    }
    LL t = (x-a)/(a-b);
    ans = (t%mod*(a%mod))%mod;
    x -= (a-b)*t;
    (ans += x-x%a) %= mod;
    x = x/a*b + x%a;
    (ans += x) %= mod;
    cout << ans << endl;

}

