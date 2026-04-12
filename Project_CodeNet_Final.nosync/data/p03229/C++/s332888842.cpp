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
    rep(i, n) cin >> a[i];
    sort(a.rbegin(), a.rend());
    ll ans = 0;
    rep(ri, 2) {
        ll sum = 0;
        if (ri) {
            if (!(n&1)) {
                rep(i, n / 2) {
                    if (i == n / 2 - 1) {
                        sum += a[i];
                    }
                    else {
                        sum += a[i] * 2;
                    }
                }
                rep(i, n / 2) {
                    if (i == 0) {
                        sum -= a[i+n/2];
                    }
                    else {
                        sum -= a[i+n/2] * 2;
                    }
                }
            }
            else {
                rep(i, n / 2 + 1) {
                    if (i == n / 2 || i == n / 2 - 1) {
                        sum += a[i];
                    }
                    else {
                        sum += a[i] * 2;
                    }
                }
                rep(i, n / 2) {
                    sum -= a[i+n/2+1] * 2;
                }
                //cout << sum << endl;
            }
        }
        else {
            if (!(n&1)) {
                rep(i, n / 2) {
                    if (i == n / 2 - 1) {
                        sum += a[i];
                    }
                    else {
                        sum += a[i] * 2;
                    }
                }
                rep(i, n / 2) {
                    if (i == 0) {
                        sum -= a[i+n/2];
                    }
                    else {
                        sum -= a[i+n/2] * 2;
                    }
                }
            }
            else {
                rep(i, n / 2) {
                    sum += a[i] * 2;
                }
                rep(i, n / 2 + 1) {
                    if (i == 0 || i == 1) {
                        sum -= a[i+n/2];
                    }
                    else {
                        sum -= a[i+n/2] * 2;
                    }
                }
                //cout << sum << endl;
            }
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
