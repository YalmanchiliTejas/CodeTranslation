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

ll ceil(ll a, ll b) {  // a÷b以上の最小の整数
    if(a%b == 0) {
        return a/b;
    }
    else {
        return a/b + 1LL;
    }
}

int main() {
    ll k, a, b;
    cin >> k >> a >> b;

    if(k <= a) {
        cout << 1 << endl;
        return 0;
    }

    if(a <= b) {
        cout << -1 << endl;
        return 0;
    }

    ll c = a-b;
    ll ans = 2LL*ceil(k-a, c) + 1LL;

    cout << ans << endl;
    return 0;
}