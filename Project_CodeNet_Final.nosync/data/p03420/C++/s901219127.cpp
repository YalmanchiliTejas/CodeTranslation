#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n, k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    if(k == 0) finish(1LL * n * n);
    ll ans = 0;
    for(int i = k + 1 ; i <= n ; i++){
        for(int j = 0 ; i * j <= n ; j++){
            ans += min(n, i * (j + 1) - 1) - min(n + 1, i * j + k) + 1;
        }
    }
    cout << ans << endl;
}
