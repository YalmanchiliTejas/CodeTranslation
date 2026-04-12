#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)//rep(i,回数){処理}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll n, max_num, num, ans;
    cin >> n;
    vector<ll> v(n);
    max_num = 1000000007;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        num += v[i];
        num %= max_num;
    }
    
    ans = 0;
    rep(i,n-1){
        num -= v[i];
        if (num < 0) num += max_num;
        ans += v[i] * num;
        ans %= max_num;
    }
    cout << ans << endl;
    return 0;
}