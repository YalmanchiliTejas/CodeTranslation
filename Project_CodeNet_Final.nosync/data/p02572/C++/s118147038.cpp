#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;


int main() {
    ll N = 0;
    cin >> N;
    vector<ll> A(N,0);
    ll sum = 0;
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
        sum += A.at(i);
    }
    ll ans = 0;

    for(ll i = 0; i < N; i++) {
        ans += (((sum - A.at(i))%MOD)*A.at(i))%MOD;
        ans %= MOD;
    }
    
    if(ans%2) {
        cout << (ans + MOD)/2 << endl;
    } else {
        cout << ans/2 << endl;
    }



    return 0;
}