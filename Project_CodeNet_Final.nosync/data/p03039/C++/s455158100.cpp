#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll MOD = 1000000007;

template <typename T>
class ModCalc{
public:
    ModCalc(T MOD){
        mod = MOD;
    }

    T add(T a, T b){
        return (a + b) % mod;
    }

    T sub(T a, T b){
        return (a - b) % mod;
    }

    T multi(T a, T b){
        return ((a % mod) * (b % mod)) % mod;
    }

    T power(T a, T n){
        T res = 1;
        while(n){
            if(n&1) res = multi(res, a);
            a = multi(a, a);
            n >>= 1;
        }
        return res;
    }

    T div(T a, T b){
        return multi(a, power(b, mod-2));
    }

    T comb(T n, T k){
        T res = 1;
        for(int i=0; i<k; i++){
            res = multi(res, n-i);
            res = div  (res, i+1);
        }
        return res;
    }
private:
    T mod;
};


int main()
{
    ll N, M, K;
    cin >> N >> M >> K;

    ModCalc<ll> mod(MOD);

    ll res_N = 0;
    ll res_M = 0;
    for(ll i=1;i<N;i++){
        res_N = mod.add(res_N, mod.multi(i, N-i));
    }
    res_N = mod.multi(res_N, mod.power(M,2));
    for(ll i=1;i<M;i++){
        res_M = mod.add(res_M, mod.multi(i, M-i));
    }
    res_M = mod.multi(res_M, mod.power(N,2));

    auto res = mod.add(res_N, res_M);
    res = mod.multi(res, mod.comb(N*M-2, K-2));
    cout<<res<<endl;
    return 0;
}


