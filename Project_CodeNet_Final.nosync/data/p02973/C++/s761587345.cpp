#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    map<ll, int> num;
    ll a;
    for ( int i = 0; i < N; i++ ) {
        cin >> a;
        a = -a;
        auto x = num.upper_bound(a);
        if ( x == num.end() ) {
            num[a]++;
        } else {
            num[a]++;
            num[x->first]--;
            if ( num[x->first] == 0 ) {
                num.erase(x->first);
            }
        }
    }
    ll s = 0;
    for( auto x : num ) {
        s += x.second;
    }
    return s;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}