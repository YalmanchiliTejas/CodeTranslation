#include "bits/stdc++.h"
using namespace std;
using LL = long long;
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
# define FOR(i,tptpt,ypypy)   for(LL i=(tptpt);i<(ypypy);i++)
# define REP(i,upupu)         FOR(i,0,upupu)

int n;
LL a[202020];
const LL mod = 1e9 + 7;
int main(){
    cin >> n;
    LL sum = 0;
    REP(i, n){
        cin >> a[i];
    }
    LL ans = 0;
    for(int i = n - 1;i >= 0;i--){
        (ans += sum * a[i]) %= mod;
        (sum += a[i]) %= mod;
    }
    cout << ans << endl;
}