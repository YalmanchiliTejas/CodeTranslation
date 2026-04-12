#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&j : v) scanf("%d", &j);
    if(n&1){
        vector<ll> dp1(n/2+1), dp2(n/2+1);
        for (int i = 0; i < n/2; ++i) {
            dp1[i+1] = dp1[i] + v[2*i];
            dp2[i+1] = max(dp1[i], dp2[i]) + v[2*i+1];
        }
        vector<ll> dq1(n/2+1), dq2(n/2+1);
        for (int i = n/2-1; i >= 0; --i) {
            dq1[i] = max(dq2[i+1], dq1[i+1]) + v[i*2+1];
            dq2[i] = dq2[i+1] + v[i*2+2];
        }
        ll ans = -INF<ll>;
        for (int i = 0; i < n/2; ++i) {
            ans = max({ans,
                       dp1[i]+dq1[i+1]+max(v[2*i], v[2*i+1]),
                       dp1[i]+dq2[i+1]+max({v[2*i], v[2*i+1], v[2*i+2]}),
                       dp2[i]+dq1[i+1]+v[2*i+1],
                       dp2[i]+dq2[i+1]+max({v[2*i+1], v[2*i+2]})
                       });
        }
        cout << ans << "\n";
    }else {
        vector<ll> dp1(n/2+1);
        vector<ll> dp2(n/2+1);
        for (int i = 0; i < n/2; ++i) {
            dp1[i+1] = dp1[i] + v[2*i];
        }
        for (int i = n/2-1; i >= 0; --i) {
            dp2[i] = dp2[i+1] + v[2*i+1];
        }
        ll ans = -INF<ll>;
        for (int i = 0; i < n/2+1; ++i) {
            ans = max(ans, dp1[i]+dp2[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}