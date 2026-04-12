#include<bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int main(){
    int n;
    cin >> n;
    vector<long long>v(n + 3), suff(n + 3);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    suff[n + 1] = 0;
    for(int i = n; i >= 0; i--){
        suff[i] = (suff[i + 1] + v[i]) % mod;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        ans = (ans + v[i] * suff[i + 1]) % mod;
    }
    cout << ans;
    return 0;
}