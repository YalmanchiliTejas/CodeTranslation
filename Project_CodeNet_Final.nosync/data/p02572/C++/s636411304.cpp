#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> sum(n + 1, 0);
    int mod = 1e9 + 7;
    long long ans = 0;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }
    for (int i = 0; i < n - 1; ++i){
        long long add = 1;
        long long temp = sum[n] - sum[i + 1];
        temp %= mod;
        add *= a[i];
        add *= temp;
        ans += add;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}