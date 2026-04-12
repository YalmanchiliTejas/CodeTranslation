#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
const ll MOD = 1e9 + 7;
ll a, sol = 0;
ll arr[200005];
ll suf[200005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = n-1; i >= 0; i--) {
        suf[i] = (suf[i + 1] + arr[i]) % MOD;
    }

    for (int i = 0; i < n; i++) {
        sol += arr[i] * suf[i + 1];
        sol %= MOD;
    }

    cout << sol << endl;
}
