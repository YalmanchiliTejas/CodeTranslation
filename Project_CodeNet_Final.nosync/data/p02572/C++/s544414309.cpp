#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for (int i = 0;i < n;i++)
#define MOD (1000000007)

int main() {
    ull n;
    cin >> n;
    ull input;
    vector<ull> vec;
    vector<ull> sum;
    vec.push_back(0);
    sum.push_back(0);
    for (ull i = 1;i <= n;i++){
        cin >> input;
        vec.push_back(input);
        sum.push_back(sum[i - 1] + input); 
    }

    ull ans = 0;
    for (ull i = 1;i < n;i++) {
        // ans = (ans + (vec[i] * (sum[n] - sum[i]) % MOD)) % MOD;
        ans += ((vec[i] % MOD) * ((sum[n] - sum [i]) % MOD) % MOD);
        ans %= MOD; 
    }

    cout << ans << endl;

    return (0);
}
