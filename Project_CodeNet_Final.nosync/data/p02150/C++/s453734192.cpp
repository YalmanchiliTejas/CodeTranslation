#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007LL;
const int INF = LLONG_MAX;

signed main(){
    
    int a, b, x; cin >> a >> b >> x;
    if(x < a) cout << x % MOD << endl;
    else{
        int ans = (( (x - b) / (a - b)) % MOD) * (b % MOD);
        cout << (ans + x) % MOD << endl;
    }
    return 0;
}
