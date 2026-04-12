//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 1e5 + 5;
const int M = 19;
const int Q = 2e5 + 5;
const ll OO = 1e18;
const int mod = 1e9 + 7;

int n,a[N],ans;
multiset<pair<int,int> > s;

int main() {

    ios_base::sync_with_stdio(false);
    //cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        auto x = s.lower_bound({a[i],0});
        if(x==s.begin()) ++ans;
        else s.erase(*(--x));
        s.insert({a[i],i});
    }

    cout << ans << '\n';

    return 0;
}