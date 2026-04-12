// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define fo(i,n)             for(int i=0;i<n;i++)
#define nl                  "\n"
#define ff                  first
#define ss                  second
#define int                 long long
#define pb                  push_back
#define mp                  make_pair
#define vec(x)              vector<x>
#define matrix(x)           vector<vector<x>>
#define sz(x)               (int)x.size()
#define mem(a,b)            memset(a, b, sizeof a)
#define vii                 vector<pair<int,int>>
#define pii                 pair<int,int>
#define vi                  vector<int>
#define mii                 map<int,int>
#define uii                 unordered_map<int,int,custom_hash>
#define pqb                 priority_queue<int>
#define pqs                 priority_queue<int,vi,greater<int> >
#define gcd(a,b)            __gcd(a,b)
#define lcm(a,b)            (a*(b/gcd(a,b)))
#define setbits(x)          __builtin_popcountll(x)
#define zrobits(x)          __builtin_ctzll(x)
#define mod                 1000000007
#define MOD                 998244353
#define inf                 1e18
#define ps(x,y)             fixed<<setprecision(y)<<x
#define mk(arr,n,type)      type *arr=new type[n];
#define w(x)                int x; cin>>x; while(x--)
#define all(v)              v.begin(),v.end()
#define rep(i,begin,end)    for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define len(s)              s.length()

#define watch(x)            cout << #x << " = " << x << endl

#define deb(...) cerr << "[" << #__VA_ARGS__ << "] : [", DBG(__VA_ARGS__)
void DBG() { cerr << "]\n";}
template<typename T, typename ...Args> void DBG(T first, Args... args)
{cerr << first; if(sizeof...(args))cerr<<", "; DBG(args...); }

mt19937                     rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; //for storing unique elements
typedef tree<int , null_type , less_equal<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_set; //for repeating elements
 
int power(int a,int b,int m=mod)
{int ans=1;while(b>0){if(b&1)ans=(ans*a)%m;a=(a*a)%m;b>>=1;}
return ans;}

void babuBhaiya()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int N = 1e5+1;
const double pi = acos(-1);

/*/-----------------------Modular Arithmetic---------------/*/
inline int add(int x,int y){
    x+=y;
    if (x>=mod) return x-mod;
    return x;
}
inline int sub(int x,int y){
    x-=y;
    if (x<0) return x+mod;
    return x;
}
inline int mul(int x,int y){
    return (x*1ll*y)%mod;
}
/*/-----------------------------Code begins----------------------------------/*/

void solve(){

    int n,x,m; cin>>n>>x>>m;
    vi v;
    mii id;
    int rem = n-1, ans = x;
    v.pb(x);
    for(int i = 1;i<n;i++){
        int a = v[i-1];
        id[a] = i-1;
        a *= a;
        a %= m;
        if(id.count(a)){
            int len = 0;
            int sum = 0;
            int l = sz(v);
            for(int j = id[a];j<l;j++){
                sum += v[j];
                len++;
            }
            int x = rem/len;
            ans += x*sum;
            rem %= len;
            for(int j = id[a];rem;j++, rem--){
                ans += v[j];
            }
            break;
        }
        rem--;
        ans += a;
        v.pb(a);
    }
    cout<<ans;
}

 
int32_t main()
{
    babuBhaiya();

    int t;

    t = 1;
    //cin>>t;

    while(t--){
        solve();
    }
    
    return 0;
}