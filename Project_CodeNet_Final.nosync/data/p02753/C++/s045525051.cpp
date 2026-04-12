#include <bits/stdc++.h>
using namespace std;
// #include <bits/stdtr1c++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
 
 
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
 
/// Typedef
typedef long long           ll;
typedef unsigned long       ul;
typedef unsigned long long  ull;
typedef vector<int>         vi;
typedef vector<vi>          vvi;
typedef vector<ll>          vll;
typedef pair<int,int>       pii;
typedef pair<ll,ll>         pll;
 
#define mt                  make_tuple
#define fbo                 find_by_order
#define ook                 order_of_key
#define UB                  upper_bound
#define LB                  lower_bound
#define pb                  push_back
#define ppb                 pop_back
#define MP                  make_pair
#define ff                  first
#define ss                  second
#define sf                  scanf
#define pf                  printf
#define loop(i, y)          for(int i=0; i<int(y); i++)
#define FOR(i, x, y)        for(int i=int(x); i<int(y); i++)
#define ROF(i, x, y)        for(int i=int(x); i>=int(y); i--)
#define all(c)              c.begin(), c.end()
#define sz(c)               int(c.size())
#define SQR(x)              ((x)*(x))
#define clr(x, y)           memset(x, y, sizeof(x))
#define si(x)               scanf("%d", &x)
#define sii(x, y)           scanf("%d %d", &x, &y)
#define siii(x, y, z)       scanf("%d %d %d", &x, &y, &z)
#define sl(x)               scanf("%lld", &x)
#define sll(x, y)           scanf("%lld %lld", &x, &y)
#define slll(x, y, z)       scanf("%lld %lld %lld", &x, &y, &z)
#define FastIO              ios_base::sync_with_stdio(false)
#define FixedPrecision(x)   ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(x); cin.tie(0);
#define bitCheck(N,in)      ((bool)(N&(1LL<<(in))))
#define bitOff(N,in)        (N&(~(1LL<<(in))))
#define bitOn(N,in)         (N|(1LL<<(in)))
#define bitFlip(a,k)        (a^(1LL<<(k)))
#define popCount(x)         __builtin_popcount(x)
#define popCountLL(x)       __builtin_popcountll(x)
#define int2Bin(x, y)       bitset<y> z=x; cout<<z.to_string()<<endl;
#define tr(it, container)   for(auto it = container.begin(); it != container.end(); it++)
#define unq(v)              (v).erase(unique(all(v)),v.end())
#define common(a,b)         sort(all(a)), sort(all(b)), a.erase(set_intersection(all(a),all(b),a.begin()),a.end())
#define uncommon(a,b)       sort(all(a)), sort(all(b)), a.erase(set_symmetric_difference(all(a),all(b),a.begin()),a.end())
#define DB(x)               cout << #x << " = " << x << endl
#define DDB(x,y)            cout << #x << " = " << x << "   " << #y << " = " << y << endl
#define DDDB(x,y,z)         cout << #x << " = " << x << "   " << #y << " = " << y << "   " << #z << " = " << z << endl
#define ran(a, b)           ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
/// template <typename T> using orderset = tree <T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
/// *X.find_by_order(k) //returns the kth largest element.(0-based)
/// X.order_of_key(val) //returns the no. of values less than val
 
 
template <class T> inline T bigMod(T p,T e,T M){ ll ret = 1; for(; e > 0; e >>= 1){ if(e & 1) ret = (ret * p) % M; p = (p * p) % M; } return (T) ret;}
template <class T> inline T modInverse(T a,T M){return bigMod(a,M-2,M);}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/gcd(a,b))*b;}
template <class T> inline string int2String(T a){ostringstream str; str<<a; return str.str();}
template <class T> inline T string2int(string a){stringstream str(a); T b; str>>b; return b;}
template <class T> inline void read(T &r){
    r=0;int f=1;char ch=getchar();
    while (ch<'0' or ch>'9'){f=(ch=='-'?-1:1), ch=getchar();}
    while (ch>='0' and ch<='9'){r=r*10+ch-'0', ch=getchar();}
    r*=f;
}
const int dr[] = { 0,  1,  0, -1,   -1,  1,  1, -1,   -2, -2,  2,  2, -1, -1,  1,  1};
const int dc[] = { 1,  0, -1,  0,    1,  1, -1, -1,   -1,  1, -1,  1, -2,  2, -2,  2};
#ifdef VAMP
     #define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cout << name << " = " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cout.write(names, comma - names) << " = " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define dbg(...)
#endif
///******************************************START******************************************
 
/// Constants
#define MAX                 200005
#define MOD                 1000000009 
#define base                1000000007
#define eps                 1e-9
#define INF                 1<<20    // 2,305,843,009,213,693,952
#define inf                 2000000000       // 536,870,912
#define PI                  acos(-1.0)  // 3.1415926535897932
// #define INF              0x3f3f3f3f3f3f3f3f
// #define inf              0x3f3f3f3f
 
 
int main(){
    #ifdef VAMP
        clock_t tStart = clock();
        freopen("C:\\Users\\raiha.DESKTOP-5M3GJRN\\Videos\\Raihan\\input.txt", "r", stdin);
        freopen("C:\\Users\\raiha.DESKTOP-5M3GJRN\\Videos\\Raihan\\output.txt", "w", stdout);
    #endif
    string str;
    cin>>str;
    FOR(i,0,sz(str)-1){
        if(str[i]!=str[i+1]){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    #ifdef VAMP
       printf("\n>>Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
    return 0;
}
/*
Don't Forget to change MOD Value according to problem
statment
check input limit and overflow.
*/
