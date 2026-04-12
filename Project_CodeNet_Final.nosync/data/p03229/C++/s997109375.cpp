#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    int m = n/2;

    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());  // aを降順ソート

    ll ans = 0;
    if(n%2 == 0) {  // nが偶数のとき(n = 2m)
        
        rep(i, m-1) {
            ans += 2*a[i];
        }
        ans += a[m-1];
        ans -= a[m];
        for(int i = m+1; i < n; i++) {
            ans -= 2*a[i];
        }

    }
    else {  // nが奇数のとき(n = 2m+1)
        
        // p_1 >= p_2 <= p_3 >= … =< p_2m >= p_(2m+1) のとき
        ll ans1 = 0;
        rep(i, m-1) {
            ans1 += 2*a[i];
        }
        ans1 += a[m-1];
        ans1 += a[m];
        for(int i = m+1; i < n; i++) {
            ans1 -= 2*a[i];
        }

        // p_1 <= p_2 >= p_3 <= … => p_2m <= p_(2m+1) のとき
        ll ans2 = 0;
        rep(i, m) {
            ans2 += 2*a[i];
        }
        ans2 -= a[m];
        ans2 -= a[m+1];
        for(int i = m+2; i < n; i++) {
            ans2 -= 2*a[i];
        }

        ans = max(ans1, ans2);
    }

    cout << ans << endl;
    return 0;
}