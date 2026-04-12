#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(ll i=0; i<n; i++)
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define sz(v) ll(v.size)

int main(){
    ll N;
    cin >> N;
    vector<ll> H(N);
    rep(i, N) {
        cin >> H[i];
    }
    ll highest = 0;
    ll counter = 0;
    rep(i, N) {
        if (highest <= H[i]) {
            counter++;
            highest = H[i];
        }
    }
    cout << counter << endl;
    return 0;
}