#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
const int N = 2e5 + 10;
const ll inf = 1e15 + 42;
#define endl "\n"
const ll mod = 1000000007;

typedef tree<pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

//Ordered set
//pbds s1

ll n, x, m;

ll MOD (ll a, ll val) {
    if (a < 0)
        a += val;
    return (a % val);
}

void testCase() {
    cin >> n >> x >> m;
    map <ll, int> track;
    list<ll> store;
    ll ans = x;
    n--;
    ll prev = x;
    track[x] = 1;
    store.push_back (x);
    while (n) {
        prev = MOD(prev*prev, m);
        if (track[prev]) {
            //it is a loop
            break;
        }
        else {
            track[prev] = 1;
            store.push_back (prev);
            ans += prev;
            n--;
        }
    }
    if (n) {
        //find prev;
        while (store.front() != prev) {
            store.pop_front();
        }
        ll cnt = ll (store.size());
        ll sum = 0;
        for (ll v : store)
            sum += v;
        ll take = n / cnt;
        ans = ans + (take)*sum;
        n = n - take*cnt;
        while (n--) {
            ans += store.front();
            store.pop_front();
        }
    }
    cout << ans << endl;
}
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}