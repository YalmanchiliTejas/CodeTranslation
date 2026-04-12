#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    vector<long long> tot(n,0);
    long long mod = 1e9 + 7;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(i == 0) tot[i] = a[i];
        else{
            tot[i] += (tot[i-1] + a[i]) % mod;
            tot[i] %= mod;
        }
    }
    long long ans = 0;
    for(int i=1; i<n; i++){
        ans += (a[i] * tot[i-1]) % mod;
        ans %= mod;
    }
    cout << ans << endl;
}