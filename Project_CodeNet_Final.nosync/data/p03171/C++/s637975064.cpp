
//Chaos///

#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> 
//using namespace boost::multiprecision; 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#if DEBUG && !ONLINE_JUDGE
    #define debug(args...)     (Debugger()) , args
    class Debugger
    {
        public:
        Debugger(const std::string& _separator = ", ") :
        first(true), separator(_separator){}
        template<typename ObjectType>
        Debugger& operator , (const ObjectType& v)
        {
            if(!first)
                std::cerr << separator;
            std::cerr << v;
            first = false;
            return *this;
        }
        ~Debugger() {  std::cerr << endl;}
 
        private:
        bool first;
        std::string separator;
    };
    template <typename T1, typename T2>
    inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
    {
        return os << "(" << p.first << ", " << p.second << ")";
    }
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    {
        bool first = true;
        os << "[";
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << ", ";
            os << v[i];
            first = false;
        }
        return os << "]";
    }
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first)
                os << ", ";
            os << *ii;
            first = false;
        }
        return os << "]";
    }
    template<typename T1, typename T2>
    inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first)
                os << ", ";
            os << *ii ;
            first = false;
        }
        return os << "]";
    }
#else
    #define debug(args...)                 
#endif
const int mod = 1000000007;
// const int mod = 998244353;
#define ok order_of_key
#define fo find_by_order
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ll long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define repp(i,n) for(int i=(0);i<(n);i++)
#define repr(i,n) for(int i=(n);i>=0;i--)
#define reprr(i,n) for(int i=(n);i>0;i--)
#define repl(i,a,b) for(ll i=(a);i<(b);i++)
#define newl cout<<'\n'
#define inf 1000000000
#define repaa(i,a) for(auto i=a.begin();i!=a.end();++i)
#define pb push_back 
#define test cout<<"test"<<endl
#define tc int tt;cin>>tt;while(tt--)
#define start int tt;tt=read();while(tt--)
#define nl "\n"
#define startk int tt;cin>>tt;for(int kk=1;kk<=tt;kk++)
#define mem(v,i) memset(v,i,sizeof(v))//Use mem(v,60) to initialize with 10^9
#define all(x) x.begin(), x.end()
#define inf1 1e18
#define repa(i,a) for (auto i : a)
#define X first
#define Y second
#define lb lower_bound
#define ub upper_bound
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define dec(v) sort(v.begin(),v.end(),greater<int>());
#define in(a,n) repp(jjj,n)cin>>a[jjj];
#define re(a,n) repp(jjj,n)a[jjj]=read();
#define retree(a,m) repp(i,m){int tmp1=read()-1,tmp2=read()-1;a[tmp1].eb(tmp2);a[tmp2].eb(tmp1);}
#define intree(a,m) repp(i,m){int tmp1,tmp2;cin>>tmp1>>tmp2;tmp1--,tmp2--;a[tmp1].eb(tmp2);a[tmp2].eb(tmp1);}
#define ins insert
#define case(ans) cout << "Case #" << kk << ':' << ' ' << ans << nl
#define er erase
#define sz(a) (int)(a.size())
#define print(x,n,k) repp(i,n){repp(j,k)cout<<x[i][j]<<"  ";newl;} 
#define mt make_tuple
#define eb emplace_back
#define bp(i) __builtin_popcountll(i)
#define precision(x) cout << fixed << setprecision(x);
#define si set<int>
#define usi unordered_set<int>
#define sl set < ll >
#define usl unordered_set < ll >
#define sip set < ip >
#define sil set < il > 
#define mi map<int , int >
#define umi unordered_map<int , int >
#define ml map < ll , ll>
#define uml unordered_map < ll , ll>
#define mip map<ip , int>   
#define mmx(x1,x2) min(x1,x2) , max(x1,x2)
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
#define mxe max_element
#define mne min_element
#define srt(v) sort(all(v))
#define rsrt(v) sort(v.rbegin(), v.rend())
typedef long double ld;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<ll> vl;
typedef vector < vi > vii;
typedef vector<pair<int,int>> vip;
typedef vector<pair<ll,ll>> vil;
typedef vector < vl > vll;
typedef pair<int, int> ip;
typedef pair<ll, ll> il;
typedef tuple<int,int,int> state;
typedef tuple<ll,ll,ll> statel;
const int dx[4]={1,0,0,-1};
const int dy[4]={0,1,-1,0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
#ifdef Fading
#define gc getchar
#endif
#ifndef Fading
inline char gc(){static char now[1<<16],*S,*T;if (T==S){T=(S=now)+fread(now,1,1<<16,stdin);if (T==S) return EOF;}return *S++;}
#endif
inline ll read(){register ll x=0,f=1;char ch=gc();while (!isdigit(ch)){if(ch=='-')f=-1;ch=gc();}while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=gc();}return (f==1)?x:-x;}
template<typename T>T Min(T v) {return v;}template<typename T, typename... Args>T Min(T first, Args... args) {return min(first , Min(args...));}
template<typename T>T Max(T v) {return v;}
template<typename T, typename... Args> T Max(T first, Args... args) {return max(first , Max(args...));}
template<typename T> T mult(T v) {return v;} template<typename T, typename... Args>T mult(T first, Args... args) {return mult((first%mod * mult(args...))%mod);}
template<class T , class U> inline bool remax(T &a, U b) { return a < b ? a = b, 1 : 0; }
template<class T , class U> inline bool remin(T &a, U b) { return a > b ? a = b, 1 : 0; }
template<class A, class B> void add(A &a, B b){a += b;if(a >= mod) a -= mod;if(a < 0) a += mod;}
template<class A, class B> ll addr(A a, B b){a += b;if(a >= mod) a -= mod;if(a < 0) a += mod;return a;}
template<class T1,class T2>
T2 min(T1 a,T2 b){return min((T2)a,b);}
template<class T1,class T2>T2 max(T1 a,T2 b){return max((T2)a,b);}
template <class T1>void kill(T1 ans){cout << ans << endl;exit(0);}
template<class A> void pnt(A a[],int st,int en) {rep(i,st,en) cout << a[i] << ' ' ; newl;}
template<class A> void pnt(A a[],int en) {repp(i,en) cout << a[i] << ' ' ; newl;}
template<class A> void pnt(vector<A>a) {repa(i,a) cout << i << ' ' ; newl;}
template<class A> void pnt(set<A>a) {repa(i,a) cout << i << ' ' ; newl;}
template<class A> void pnt(unordered_set<A>a) {repa(i,a) cout << i << ' ' ; newl;}
template<class A,class B> void pnt(pair<A,B>a){cout << a.X << ' ' << a.Y << nl;}

ll nc2(ll a){return a * (a - 1) / 2;}
ll setbit(ll num, ll kk){ return 1LL*(num|(1LL<<kk)); }
ll unsetbit(ll num, ll kk){ return 1LL*(num&~(1LL<<kk)); }
ll invertbit(ll num, ll kk){ return 1LL*(num^(1LL<<kk)); }
bool kthbit(ll num, ll kk){ return num&(1LL<<kk); }
bool matchpar(ll a, ll b){return (a&1) == (b&1);}
ll mceil(ll a, ll b){return a/b + (ll)(a%b > 0);}
ll poww(ll a, ll b,ll m = mod){ll val = 1;a %= m;while (b > 0){if (b & 1) val = (a * val) % m;a = (a * a) % m;b >>= 1;}return val;}
ll inv(ll a){return poww(a , mod - 2);}
ll gcdll(ll x, ll y){return y == 0 ? x : gcd(y, x % y);}
int mylog(ll x , ll y){if(x == 0) return -1;return mylog(x/y,y) + 1;}

//-----------------------------------------------------end--------------------------------------//

const int N = 3005;
ll dp[N][N];
ll a[N];

ll solve(int l, int r){
    if(l > r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    ll &ans = dp[l][r];
    if(l == r) return ans = a[l];
    return ans = max(-solve(l + 1 , r) + a[l] , -solve(l , r - 1) + a[r]);
}

signed main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    in(a,n);
    mem(dp , -1);
    cout << solve(0,n-1);
}   