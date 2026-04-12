#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using vll = vector<ll>;

int N;
vll A;

bool f(ll k) {
    ll sum = 0;
    rep(i,A.size()) {
        sum += (A[i]+k+1)/(N+1);
    }
    return sum <= k;
}

int main() {
    cin >> N;
    A.resize(N);
    rep(i,N) cin >> A[i];
    ll sum = 0;
    rep(i,N) sum += A[i];
    for (ll i = sum-N*(N-1); ; i++) {
        if (f(i)) {
            cout << i << endl;
            return 0;
        }
    }
}