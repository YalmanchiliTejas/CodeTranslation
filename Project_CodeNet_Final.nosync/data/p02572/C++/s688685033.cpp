#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<ll> arr(N);
    ll sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
        sum %= MOD;
    }

    ll ans = 0;
    for(int i = 0; i < N; i++) {
        sum -= arr[i];
        if(sum < 0) sum += MOD;
        ans += arr[i] * sum;
        ans %= MOD;
    }
    cout << ans;
}