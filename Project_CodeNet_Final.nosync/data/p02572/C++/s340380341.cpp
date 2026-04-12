#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;

ll A[200001], S[200001];


int main() {
    ll N;
    ll MOD = 1000000007;

    cin >> N;
    for (ll i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] %= MOD;
    }

    S[N] = A[N];
    for (ll i = N - 1; i >= 2; i--) {
        S[i] = (S[i+1] + A[i]) % MOD;
    }
    /*
    for (ll i = 1; i <= N; i++) {
        printf("%ld: %ld, %ld\n", i, A[i], S[i]);
    }
    */
    ll sum = 0;
    for (ll i = 1; i <= N-1; i++) {
        ll tmp = (A[i] * S[i+1]) % MOD;
        sum += tmp;
        //printf("%ld * %ld = %ld, %ld\n", A[i], S[i+1], tmp, sum);
        sum %= MOD;
    }

    cout << sum << endl;
}