#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

int main(){
    ll N, K;
    cin >> N >> K;
    if (K==0){
        cout << N*N << endl;
        return 0;
    }
    ll res = 0;
    for(ll b=K+1;b<N+1;b++){
        ll dif1 = ((N+1)/b)*(b-K);
        ll dif2 = max((N+1)%b - K, 0ll);
        res += (dif1+dif2);
        //cout << "b: " << b << ", dif1: " << dif1 << ", dif2: " << dif2 << endl;
    }
    cout << res << endl;
    return 0;
}