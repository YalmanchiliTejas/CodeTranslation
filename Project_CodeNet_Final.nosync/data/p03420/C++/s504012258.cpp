#include<bits/stdc++.h>
using namespace std;

int main(){

    long long n, k; cin >> n >> k;
    long long ans = 0;
    for(int b = k + 1; b <= n; b++){
        long long c = (n + 1) / b;
        ans += c * (b - k);
        long long temp = (n + 1) % b;
        if(temp > k) ans += temp - k;
    }

    if(k == 0) cout << n*n << endl;
    else cout << ans << endl;
    return 0;
}