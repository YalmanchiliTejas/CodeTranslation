#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;

ll A[200001];

int main() {
    ll N;
    ll MOD = 1000000007;
    ll sum = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        sum += A[i];
        sum %= MOD;
    }

    ll ans = 0;
    for (int i = 1; i < N; i++) {
        sum -= A[i];
        if (sum < 0) { sum += MOD; }
        //printf("sum: %d, a: %d\n", sum, A[i]);
        ans += sum * A[i];
        ans %= MOD;
    }

    cout << ans << endl;
}