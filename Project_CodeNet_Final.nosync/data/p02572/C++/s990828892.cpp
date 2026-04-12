#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll N;
    cin >> N;

    vector<ll> A(N);
    ll ans = 0;
    ll sum = 0;
    ll seki = 0;
    ll mod = 1000000007;

    for (ll i=0; i<N; i++){
        cin >>A.at(i);
    }

    for (ll i=0; i<N; i++){
        sum += A.at(i);
    }

    for (ll i=0; i<N-1; i++){
        sum -= A.at(i); 
        seki = A.at(i) * (sum % mod) % mod;
        ans = (ans + seki) % mod;

    }
    cout << ans << endl;
}