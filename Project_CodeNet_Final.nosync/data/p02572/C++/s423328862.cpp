#include <bits/stdc++.h>
using namespace std;

int main() {
    int MOD = 1000000007;
    int n;
    cin >> n;
    vector<long long> vec(n);
    for (int i=0; i < n; i++) cin >> vec.at(i);

    vector<long long> rui(n+1);
    for (int i=0; i < n; i++) rui[i+1] = rui[i]+vec[i];

    long long ans = 0;
    long sum;
    for (int i=0; i < n; i++) {
        sum = (rui[n] - rui[i+1])%MOD;
        ans += vec[i]*sum;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}

