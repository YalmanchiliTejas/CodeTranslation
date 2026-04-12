#pragma GCC optimize ("-O3")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;

#define all(c) (c).begin(),(c).end()
#define endl "\n"
#define ff first
#define ss second
#define allr(c) (c).rbegin(),(c).rend()
#define ifr(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pof pop_front
#define pob pop_back
#define pb emplace_back
#define pf emplace_front
#define fstm(m,n,r) m.reserve(n);m.max_load_factor(r)
#define mp make_pair
#define mt make_tuple
#define inf LLONG_MAX
#define os tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
const double PI = acos(-1);
typedef complex<double> cd;
typedef long long ll;
ll gcd(){return 0ll;} template<typename T,typename... Args> T gcd(T a,Args... args) { return __gcd(a,(__typeof(a))gcd(args...)); }
typedef map<ll,ll> mll;
typedef map<string,ll> msll;
typedef unordered_map<ll,ll> umap;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mod 1000000007 
#define N 100001

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    ll a[n];
    ifr(i,0,n) cin>>a[i];
    ll dp[n][n][2];
    ifr(i,0,n) ifr(j,0,n) ifr(t,0,2) dp[i][j][t]=0;
    ifr(i,0,n) {
        dp[i][i][0]=a[i];
        dp[i][i][1]=-a[i];
    }
    for(int i=n-2;i>=0;i--) {
        for(int j=i+1;j<n;j++) {
            dp[i][j][0] = max(dp[i+1][j][1]+a[i],dp[i][j-1][1]+a[j]);
            dp[i][j][1] = min(dp[i+1][j][0]-a[i],dp[i][j-1][0]-a[j]);
        }
    }
    cout<<dp[0][n-1][0]<<endl;
    return 0;
}