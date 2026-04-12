#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, s, mx;
    cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<long long> accumulate(s + 1, 0);
    long long ans = 0, mod = 998244353;
    for (int i = 0; i < n; i++){
        vector<long long> cur(s + 1, 0);
        
        if (a[i] <= s)
            cur[a[i]] = i + 1;

        for (int j = a[i] + 1; j <= s; j++){
            cur[j] = accumulate[j - a[i]];
        }

        for (int j = 0; j <= s; j++)
            accumulate[j] = (accumulate[j] + cur[j]) % mod;
        
        ans = (ans + (n - i) * cur[s]) % mod;
    }

    cout << ans << '\n';

    return 0;
}
