#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <ctime>
#include <climits>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

#define sz(x) (int)(x.size())

typedef long long ll;
typedef tuple<int, int, int> tri;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<pi> vpi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vll> vvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef __gnu_pbds::tree<
    int,
    __gnu_pbds::null_type,
    less<int>,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update>
    ordered_set;

const ll MODULO = 1000000007;

void ftime()
{
#ifndef ONLINE_JUDGE
    cout << "\nTime: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
#endif
}

static int speed_increase = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

vll arr(2e5+1);
vll pre(2e5+1);
void solve()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>arr[i];
    for(int i=1; i<=n; ++i) {
        pre[i] = (pre[i-1]+arr[i])%MODULO;
    }
    ll sum = 0;
    for(int i=n; i>1; --i) {
        sum = (pre[i-1]*arr[i]+sum)%MODULO;
    }
    cout<<sum<<"\n";
}

int main()
{
    solve();
    // ftime();
    return 0;
}