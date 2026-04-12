// SmartCoder
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>  // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
using namespace std;

#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define minei(x) min_element(x.begin(), x.end()) - (x).begin()
#define maxei(x) max_element(x.begin(), x.end()) - (x).begin()
#define LSOne(S) (S & (-S))

#define uns(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define acusum(x) accumulate(x.begin(), x.end(), 0)
#define acumul(x) accumulate(x.begin(), x.end(), 1, multiplies<int>());
#define bits(x) __builtin_popcount(x)
#define oo INT_MAX
#define inf 1000000000
#define MAXN 200007
#define MOD 1000000007

const double pi = acos(-1.0);
const double eps = 1e-11;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
ll dp[MAXN][2];
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    dp[2][0] = v[1];
    dp[2][1] = v[2];
    for (int i = 3; i <= n; i++) {
        dp[i][1] = v[i] + max(dp[i - 2][0], dp[i - 2][1]);
        dp[i][0] = i % 2 == 0 ? v[i - 1] + dp[i - 2][0] : max(dp[i - 1][0], dp[i - 1][1]);
    }
    cout << max(dp[n][0], dp[n][1]) << endl;

    return 0;
}
