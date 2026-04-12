#include <bits/stdc++.h>

using namespace std;

long long mod = 1000000007;
int main(){
    int n;
    cin >> n;
    vector<long long>v(n);
    vector<long long>f(n);
    long long  sum = 0;
    for(int i = 0;i < n;i++){
        int item;
        cin >> item;
        v[i] = item;
        sum += item;
        sum %= mod;
        f[i] = sum;
    }
    long long ans = 0;
    for(int i = 0;i < n - 1;i++){
        long long add = f[n - 1] - f[i] + mod;
        ans += (v[i] * add)%mod;
        ans %= mod;
    }
    cout << ans << endl;
}

