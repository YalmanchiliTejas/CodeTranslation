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
#define N 10001

ll dp[N][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string k;
    int d;
    cin>>k>>d;
    ifr(i,0,N) ifr(j,0,d) dp[i][j]=0;
    dp[0][0]=1;
    ifr(i,1,N) {
        ifr(j,0,d) {
            ifr(x,0,10) {
                dp[i][(j+x)%d] = (dp[i][(j+x)%d]+dp[i-1][j])%mod;
            }
        }
    }
    ll ans = 0,sum=0,st=1,n=k.length();
    ifr(i,1,n) {
        ifr(j,1,10)
            ans=(ans+dp[i-1][((d-j)%d +d)%d ])%mod;
    }
    ifr(i,0,n) {
        ifr(j,st,int(k[i]-'0')) {
            sum=(sum+j)%d;
            ans = (ans+dp[n-i-1][(d-sum)%d])%mod;
            sum=(sum-j+d)%d;
        }
        st=0;
        sum=(sum+(k[i]-'0')+d)%d;
    }
    if(sum==0) ans=(ans+1)%mod;
    cout<<ans<<endl;
    return 0;
}