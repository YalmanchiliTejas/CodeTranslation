#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <functional>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    if(k == 0) {
        ans = n * n;
    }
    else {

        ll ct = 1;
        for(ll i = k + 1; i <= n; i++) {
            ans += (n / i) * ct;
            if(n % i != 0) {
                ll ex = n - (n % i);
                ll low = ex + k;
                ans += max((ll)0, n - low + 1);
            }
            ct++;
        }
    }
    cout << ans;

    return 0;
}

