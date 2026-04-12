#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;

int main() {
    int n; cin >> n;
    int ans = 1; int now; cin >> now;
    for(int i = 1;i < n;i++){
        int x; cin >> x;
        if(now <= x){
            now = x;
            ans++;
        }
    }
    cout << ans;
}
