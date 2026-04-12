#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod(ll x) {
    const ll d = 1e9 + 7;
    ll y = x % d;

    ll z = 0;
    if (y >= 0) {
        z = y -d;
    }
    if (y < 0) {
        z = y + d;
    }
    if (abs(y) > abs(z)) {
        return z;
    }
    else {
        return y;
    }
}

int main() {
    const ll d = 1e9 + 7;
    int N;
    cin >> N;
    vector<ll> A(N);
    for (ll& a : A) {
        cin >> a;
    }

    ll sum = 0;
    for (ll a : A) {
        sum += a;
        sum = mod(sum);
    }
    ll square = mod(sum * sum);
    ll diag = 0;
    for (auto i = 0; i < N; ++i) {
        diag += mod(A[i] * A[i]);
        diag = mod(diag);
    }
    ll y = square - diag >= 0 ? square -diag : square - diag + d;
    ll x = (y * (d+1) / 2) % d;
    cout << x << endl;

}