#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int32_t main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    vector<int> prefixSum;
    prefixSum.push_back(0);
    for(int i = 0; i < n; i++){
        prefixSum.push_back(prefixSum.back() + vec[i]);
    }
    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        ans += ((prefixSum.back() - prefixSum[i + 1]) % MOD * vec[i] % MOD) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}