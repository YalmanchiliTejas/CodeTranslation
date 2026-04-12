#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>

#define mod 1000000007
#define MAXX  1e18
#define MINN -1e18
 
#define f first
#define s second
#define ll long long
#define ull unsigned long long int
#define ld long double
#define pb push_back
#define pi pair<ll, ll>
#define pl pair<ll, ll>
#define all(a) a.begin(), a.end()
#define lb(a, key) lower_bound(all(a), key) - a.begin();
#define ub(a, key) upper_bound(all(a), key) - a.begin();
#define fastio  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define add(a, b) (((a)%mod + (b)%mod + mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod) % mod)
#define endl cout<<"\n";
#define debug(vari) cerr<< "["<< #vari << " " << (vari) << "]";endl;
#define read(a) for(auto &i: a) cin >> i;
#define out(a)  for(auto i: a) cout << i << " ";endl
#define ordered_set tree<ll, null_type, std::less<ll>, rb_tree_tag, tree_order_statistics_node_update>





using namespace __gnu_pbds;
using namespace std;

struct point {
    int x;
    int y;
};

bool cmp(point p, point q) {
    if(p.x == q.x) return p.y < q.y;
    return p.x < q.x;
}

int main() {
    fastio
    int n, m; cin >> n >> m;
    string ans = (n==m) ? "Yes" : "No";
    cout << ans;endl
}

