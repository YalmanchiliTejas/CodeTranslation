#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1010000000000000017LL;
const ll MOD = 1000000007LL;

#define REP(i, n) for(ll i = 0 ; i < n; i++)

#ifdef DEBUG
#define DBG(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)
#else
#define DBG(fmt, ...)
#endif

int main(){
    std::cout<<std::fixed<<std::setprecision(10);

    ll N;

    cin >> N;

    vector<ll> array(N);
    REP(i, N){
        cin >> array[i];
    }

    vector<ll> sums(N);
    sums[N-1] = array[N-1];
    for(int i = N-2; i >= 0; i-- ){
        sums[i] = (sums[i+1]+array[i])%MOD;
    }

    ll ans = 0;
    for(int i = 0; i < N-1; i++ ){
        ans += (sums[i+1]*array[i])%MOD;
        ans = ans%MOD;
    }

    cout << ans << endl;
}
