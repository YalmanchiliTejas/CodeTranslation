#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<iterator>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#include<climits>
#define MOD 1000000007
signed main() {
    long long int n;
    cin >> n;
    vector<long long int> v(n);
    for(long long int i = 0; i < n; ++i){
        cin >> v[i];
    }
    vector<long long int> s(n);
    s[n-1] = v[n-1] % MOD;
    for(long long int i = n-2; i >= 0; --i){
        s[i] = (s[i+1] + v[i]) % MOD;
    }
   long long int ans = 0;
    for(long long int i = 0; i < n - 1; ++i){
        ans += ((v[i] * s[i+1])) % MOD;
    }
    cout << ans%MOD << endl;
    return 0;
}
