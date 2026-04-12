#include <bits/stdc++.h>
using namespace std;
#define int long long   // aaaaaaaaaaaaaaaaaa
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define in(s,x) s.find(x) != s.end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define SIZE(buff) (sizeof(buff)/sizeof(buff[0]))
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<pair<int,int>> VPII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void chmin(int64_t& a, int64_t b){
    a = min(a, b);
}
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
template<typename T, typename U>ostream& operator << (ostream& os, pair<T, U>& pair_var)
{os << "(" << pair_var.first << ", " << pair_var.second << ")";return os;}

// head
int m,n,k,res,tmp,tmp2,tmp3,h,w,ans;
int a[3200] = {};
int b[8000100] = {};
int r[100001][25];
deque<PII> que;
string s;
map<int,VPII> kukan;
vector<PII> g[3000];
//int dp[200000];
int flag;
//VPII g2[200000];
int cost[200005];
double dp[1020][2] = {};
double dp2[1020][2] = {};
//VVI g(200005);

signed main() {
	cin.tie(0);
    ios::sync_with_stdio(false);
	cin>>n;
    rep(i,0,n){cin>>a[i];}
    res = 0;
    int MAX = 0;
    rep(i,0,n){
        if (MAX <= a[i]){
            MAX = a[i];res+=1;
        }
    }
    cout<<res<<endl;
}