#include <iostream>
#include <utility>
#include <functional>
#include <set>
#define Fi first
#define Se second
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;

//auto f = [](const pll &a, const pll &b){return a.Fi<b.Fi && a.Se<b.Se;};
//multiset<pll, function<bool(const pll &, const pll &)>> ms(f);
multiset<ll, greater<ll>> ms;

ll n;
ll a[100005];
ll ans = 0;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        ll x = a[i];

        if(ms.upper_bound(x) != ms.end()) {
            ms.erase(ms.upper_bound(x));
            ms.insert(x);
        }
        else {
            ms.insert(x);
            ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}
