#include <bits/stdc++.h>          
using namespace std;       
typedef long long ll;        

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll mod = pow(10,9) + 7;
    for (ll i=0; i<N; i++) {
        cin >> A.at(i);
        A.at(i) %= mod;
    }

    
    vector<ll> vec(N-1);
    vec.at(N-2) = A.at(N-1);

    for (ll i=N-3; i>=0; i--) {
        vec.at(i) = vec.at(i+1)+A.at(i+1);
        vec.at(i) %= mod;
    }
    
    vector<ll> seki(N-1);
    for (ll i=0; i<N-1; i++) {
        seki.at(i) = vec.at(i) * A.at(i);
        seki.at(i) %= mod;
    }
    ll sum = 0;
    for (ll i=0; i<N-1; i++) {
        sum += seki.at(i);
        sum %= mod;
    }
    cout << sum << endl;
    
}