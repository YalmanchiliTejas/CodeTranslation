#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll mod(ll val, ll m){
    ll res = val % m;
    if(res < 0) res += m;
    return res;
}

int main(){
    ll N;
    cin >> N;

    ll A[N];
    ll sum = 0;
    for(ll i = 0; i < N; i++){
        cin >> A[i];
        sum += A[i];
        sum %= MOD;
    }

    ll ans = 0;

    for(ll i = 0; i < N; i++){
        sum -= A[i];
        sum = mod(sum,MOD);
        ans += A[i] * sum;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}