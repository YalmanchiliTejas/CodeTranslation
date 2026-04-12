#include <bits/stdc++.h>
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rrepi(i,a,b) for(int i=((int)(b)-1);i>=(a);--i)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) rrepi(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define ZERO(x) memset(x,0,sizeof(x))
#define MINUS(x) memset(x,-1,sizeof(x))
#define UNIQUE(x) (x).erase(unique(ALL(x)), (x).end())
#define debug(var)  do{std::cout << #var << " : "; view(var);}while(0)
#define fi first
#define se second
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){for(const auto& v : vv){ view(v); } }
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void viewarr(T arr[], int n) { for(int i = 0; i < n; ++i) std::cout << arr[i] << " "; std::cout << std::endl; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll qp(ll a,ll b){ll ans=1;do{if(b&1)ans=1ll*ans*a;a=1ll*a*a;}while(b>>=1);return ans;}
ll qp(ll a,ll b,ll mo){ll ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5;

int main() {
    string s; cin >> s;
    bool ans = false;
    rep(i,2) if(s[i] != s[i+1]) ans = true;
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}
