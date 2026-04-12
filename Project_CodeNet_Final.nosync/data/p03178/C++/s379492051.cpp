#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;

const ll INF = 5e15;
const ll MOD = 1e9 + 7;

vector<ll> dp1;
vector<vector<ll>> dp2;


int main(){
    string K;
    cin >> K;
    ll D;
    cin >> D;
    dp1.resize(K.size() + 1);
    dp2.resize(K.size() + 1, vector<ll>(100, 0));
    for(ll i = 0; i < K.size(); i++){
        dp1[i + 1] = (dp1[i] + (K[i] - '0')) % D;
        for(ll j = 0; j < K[i] - '0'; j++) (dp2[i + 1][(dp1[i] + j) % D] += 1) %= MOD;
        for(ll j = 0; j <= 9; j++) for(ll k = 0; k < D; k++) (dp2[i + 1][(j + k) % D] += dp2[i][k]) %= MOD;
    }
    cout << (dp2[K.size()][0] + !dp1[K.size()] - 1 + MOD) % MOD << endl;
    return 0;
}
