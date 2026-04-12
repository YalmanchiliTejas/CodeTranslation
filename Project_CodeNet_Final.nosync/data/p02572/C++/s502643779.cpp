#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int n;
long long ans, sum, x;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        ans = (ans + sum * x) % MOD;
        sum = (sum + x) % MOD;
    }
    cout << ans;
    return 0;
}