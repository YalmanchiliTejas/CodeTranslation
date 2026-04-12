#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> sum(n+1);
    sum[0] = 0;
    rep(i, n) {
        cin >> a[i];
        sum[i+1] = (sum[i] + a[i]) % mod;
    }
    ll ans = 0;
    rep(i, n) {
        ll tmp = sum[n] - sum[i+1];
        //cout << tmp << endl;
        if (tmp < 0) tmp += mod; 
        ans = (ans + a[i] * tmp) % mod;
    }
    cout << ans << endl;
    return 0;
}
