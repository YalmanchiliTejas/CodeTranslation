/*************************************************************************
    > File Name: B.cpp
    > Author: HandsomeHow
    > Mail: handsomehowyxh@gmail.com 
    > Created Time: 2017/6/24 20:11:39
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define mp make_pair
#define cl(a) memset((a),0,sizeof(a))
#ifdef HandsomeHow
#define dbg(x) cerr << #x << " = " << x << endl
#else
#define dbg(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
const int inf=0x3f3f3f3f;
const double eps=1e-8;
const int mod=1000000007;
const double pi=acos(-1.0);
inline void gn(long long&x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
ll gcd(ll a,ll b){return a? gcd(b%a,a):b;}
ll powmod(ll a,ll x,ll mod){ll t=1ll;while(x){if(x&1)t=t*a%mod;a=a*a%mod;x>>=1;}return t;}
// (づ°ω°)づe★------------------------------------------------
const int maxn = 1e5+5;
struct Point{
    int x, y,id;
    void read(){ gn(x);gn(y); }
}point[maxn];
int n;
bool cmp1(Point &a, Point &b){ return a.x < b.x; }
bool cmp2(Point &a, Point &b){ return a.y < b.y; }
bool in[maxn];
struct EDGE{
    int a, b, cost;
    EDGE(int x, int y, int z){ a = x, b = y, cost = z; }
};
vector<EDGE>edges;
int p[maxn];
int findf(int x){ return x==p[x]?x:p[x]=findf(p[x]); }
void merge(int x, int y){
    x = findf(x);y = findf(y);
    if(x!=y)p[x]=y;
}
bool cmp(EDGE &a, EDGE &b){ return a.cost < b.cost; }
ll calc(){
    ll ret = 0;
    sort(edges.begin(),edges.end(),cmp);
    int sz = edges.size();
    for(int i = 0; i < sz; ++i){
        int x = findf(edges[i].a);
        int y = findf(edges[i].b);
        if(x != y){
            merge(edges[i].a,edges[i].b);
            ret += edges[i].cost;
        }
    }
    return ret;
}

int main(){
#ifdef HandsomeHow
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
#endif
    gn(n);
    rep(i,1,n)p[i]=i;
    rep(i,1,n)point[i].read();
    rep(i,1,n)point[i].id=i;
    sort(point+1,point+1+n,cmp1);
    rep(i,2,n) edges.pb(EDGE(point[i].id,point[i-1].id,point[i].x-point[i-1].x));
    sort(point+1,point+1+n,cmp2);
    rep(i,2,n) edges.pb(EDGE(point[i].id,point[i-1].id,point[i].y-point[i-1].y));
    ll ans = calc();
    printf("%lld\n",ans);
    return 0;
}

