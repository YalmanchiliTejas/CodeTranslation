#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
    s.find_by_order(k) ---> returns iterator to the element at index(from 0) k
    s.order_of_key(val) ---> number of elements that are strictly smaller than the given value
*/
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long int> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long int>> vvl;
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
typedef vector<pair<int, int>> vii;
typedef vector<pair<long long int, long long int>> vll;
#define fastIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define test() long long int tc; cin >> tc; cin.ignore(); while(tc--) 
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define MOD 1000000007
#define SMOD 998244353
#define HASH 18014398241046527
#define pq priority_queue
#define all(x) x.begin(),x.end()
#define SP(x) setprecision(x)
#define sp " "
#define inp(a) ll a;cin>>a;cin.ignore()
#define inps(a,b) ll a,b;cin>>a>>b;cin.ignore()
#define out(a) cout<<SP(20)<<a<<'\n'
#define outs(a,b) cout<<SP(20)<<a<<" "<<b<<'\n'
#define ins insert
#define er erase
#define lb lower_bound
#define ub upper_bound
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
#define inpa(a,n) ll a[n]; for(int i=0; i<n; i++){cin>>a[i];}
#define inpv(a,n) vl a; for(int i=0; i<n; i++){inp(x);a.pb(x);}
#define outa(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}cout<<'\n';
#define outv(v) for(auto i:v){cout<<i<<" ";}cout<<'\n';
set<char> vow = {'a','e','i','o','u','A','E','I','O','U'};
ll xpow(ll n, ll m){if(m==0){return 1;}else{ll x = xpow(n, m/2);if(m&1){return x*x*n;}else{return x*x;}}}
ll xmod(ll a, ll m){return (((a%m)+m)%m);}
ll xmodpow(ll n, ll m, ll y){if(m==0){return 1;}else{ll x = xmodpow(n, m/2, y);if(m&1){return xmod((xmod((xmod(x,y)*xmod(x,y)),y)*xmod(n,y)),y);}else{return xmod((xmod(x,y)*xmod(x,y)),y);}}}
template <typename T>
ll SIZEOF(T a){return (ll)a.size();}
ll xlcm(ll a, ll b){return (a/__gcd(a, b))*b;}

ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};


const int N = 1000005;




void SOLVE(){
    ll ans = 0;
    ll n;
    cin >> n;
    ll a[n];
    for(ll i=0; i<n; i++){
        cin >> a[i];
    }
    ll sum = 0;
    for(ll i=n-1; i>=0; i--){
        ans = xmod(ans + sum*a[i], MOD);
        sum = xmod(sum + a[i], MOD);
    }
    cout << ans << endl;
}

int main() {
	fastIO();
	// #ifndef ONLINE_JUDGE
    //     freopen("i.txt", "r", stdin);
    //     freopen("o.txt", "w", stdout);
	// #endif

    ll TC = 1;
    // cin >> TC;
    for(ll tc1=1; tc1<=TC; tc1++){
        // cout << "Case #" << tc1 << ": ";
        SOLVE();
    }
    printclock;
}