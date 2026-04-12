#include<iostream>
#include<vector>
using namespace std;
using ll = long long int;
const int MOD = 1E+09 + 7;

int main(){
    int n;
    cin >> n;
    vector<ll> A(n);
    for(int i = 0; i < n; i++)cin >> A[i];

    vector<ll> S(n);
    S[0] = A[0];
    for(int i = 1; i < n; i++)S[i] = S[i-1] + A[i];

    ll ans = 0;
    for(int i = 1; i < n; i++){
        ans += (A[i] * (S[i-1] % MOD)) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}