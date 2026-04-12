#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    deque<ll> d;
    rep(i, n) {
        ll a;
        cin >> a;
        int idx = lower_bound(d.begin(), d.end(), a) - d.begin() - 1;
        if (idx < 0) {
            d.push_front(a);
        }
        else {
            d[idx] = a;
        }
    }
    cout << d.size() << endl;
    return 0;
}
