#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<static_cast<int>(n);++i)
#define per(i, n) for(int i=static_cast<int>(n)-1;i>=0;--i)
#define eee(a) (cerr<<(#a)<<": "<<(a)<<'\n');
#define ppp(a) (cout<<(a)<<'\n'); 
#define cop(a) for(auto x:(a)){cerr<<(x)<<'\n';}
using ll = long long;
constexpr int dx[4]={1,0,-1,0};
constexpr int dy[4]={0,1,0,-1};
constexpr ll MOD = 1e9+7;
constexpr ll Mod = 998244353;
constexpr int INF = 1e9;
constexpr ll LINF = 1e18;
constexpr double phi = (1+sqrt(5))/2;
constexpr double pi = 3.14159265358979323846264338327950288;
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
inline ll inverse(ll n,ll m=MOD){ll a=n,b=m,x=1,y=0;while(b){ll t=a/b;a-=t*b;swap(a,b);x-=t*y;swap(x,y);}return (a%m+m)%m;}
inline void Yes(){puts("Yes");}
inline void No(){puts("No");}
inline void Judge(bool b){b?Yes():No();}
inline void YES(){puts("YES");}
inline void NO(){puts("NO");}
inline void JUDGE(bool b){b?YES():NO();}
inline ll powmod(ll b, ll e, ll m=MOD){ll r=1;while(e>0){if(e&1)r=(r%m)*(b%m)%m;b=(b%m)*(b%m)%m;e>>=1;}return r;}
inline double distance(ll x1, ll y1, ll x2, ll y2){return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));}
inline double d2r(double d){return d*pi/180;}
inline double r2d(double r){return r*180/pi;}
template<class T>inline bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}
template<typename T1,typename T2>ostream& operator<<(ostream& s,const pair<T1, T2>& p){return s <<"("<<p.first<<", "<<p.second<<")";}
template<typename T> ostream& operator<<(ostream& s,const vector<T>& v){s<<'[';for(size_t i=0;i<v.size();++i){s<<v[i];if(i<v.size()-1)s<<", ";}s<<']';return s;}

int main(){
    cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(15);
    
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;


    int ans = 0;
    if(x <= y){
        ans = 2*c*x;
        ans += min(b*(y-x), 2*c*(y-x));
    }else{
        ans = 2*c*y;
        ans += min(a*(x-y), 2*c*(x-y));
    }
    ans = min(ans, a*x+b*y);
    cout << ans << '\n';
    
    return 0;
}
