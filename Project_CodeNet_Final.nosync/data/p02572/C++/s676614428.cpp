#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long int;

const int mod = 1e9 + 7;

int main(){

    int n;
    cin >> n;

    vector<ll> values(n);
    for (auto &v: values) cin >> v;
    
    ll runningSum = 0, ans = 0;

    for (int i=0; i<n; i++){
        
        ans += values[i] * runningSum;
        ans %= mod;

        runningSum += values[i];
        runningSum %= mod;

    }

    cout << ans << endl;

    return 0;
}