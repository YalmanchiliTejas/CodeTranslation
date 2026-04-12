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
    ll x;
    cin >> n >> x;
    vector<ll> p_num(51, 0);
    vector<ll> t_num(51, 0);
    p_num[0] = 1;
    t_num[0] = 1;
    for (int i = 1; i <= 50; ++i) {
        p_num[i] = p_num[i-1] * 2 + 1;
        t_num[i] = t_num[i-1] * 2 + 3;
    }
    int idx = n;
    ll ans = 0;
    //cout << idx << " " << x << endl;
    while(1) {
        //if (x == 0 || idx < 0) break;
        if (x == 0) break;
        //cout << t_num[idx] << endl;
        if (x == t_num[idx]) {
            ans += p_num[idx];
            break;
        }
        if (x == t_num[idx] / 2LL + 1LL) {
            ans += p_num[idx-1] + 1LL;
            break;
        }
        else if (x > t_num[idx] / 2LL + 1LL) {
            ans += p_num[idx-1] + 1LL;
            x -= t_num[idx-1] + 2LL;
        }
        else {
            //cout << "test" << endl;
            x -= 1LL;
        }
        --idx;
    }
    cout << ans << endl;
    return 0;
}
