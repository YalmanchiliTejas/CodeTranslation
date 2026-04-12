#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k;
int main(){
    cin >> n >> k;
    ll ans = 0;
    if(k == 0){
        cout << ll(n) * n << '\n';
        return 0;
    }
    for(int b = k + 1; b <= n; b++){
        ans += ll(b-k) * (n/b) + max(0, (n%b)-k+1);
    }
    cout << ans << '\n';
}
