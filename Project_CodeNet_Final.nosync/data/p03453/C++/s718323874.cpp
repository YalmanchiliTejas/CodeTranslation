//Create Time: 2018-04-28 14:07:36
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <functional>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>
#include <complex>
#include <cassert>
#include <climits>
#include <iterator>
#include <tuple>
using namespace std;
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,n,a) for (int i=(n)-1;i>=(a);i--)
// #define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
// #define TST(x) std::cout<<(#x)<<":"<<(x)<<" "
#define OUT(args...) {string _s=#args;replace(_s.begin(),_s.end(),',',' ');stringstream _ss(_s);istream_iterator<string> _it(_ss);OUT_TST("\n",_it,args);}
#define TST(args...) {string _s=#args;replace(_s.begin(),_s.end(),',',' ');stringstream _ss(_s);istream_iterator<string> _it(_ss);OUT_TST("",_it,args);}
#define SZ(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define mem(f,x) memset((f), (x), sizeof(f))
#define clr(f) mem(f,0)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define eb emplace_back
#define DEBUG
void OUT_TST(string s,istream_iterator<string> it) {cerr<<s;}
template<typename T, typename... Args> void OUT_TST(string s,istream_iterator<string> it,T a,Args... args){cerr<<*it<<"="<<a<<" ";OUT_TST(s,++it,args...);}
template<class T> void rd(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long powmod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef tuple<int,int,int> tp;
/****head****/
const int N=(int)1e5+9;
const int M=(int)2e5+9;
const ll mod=(ll)1e9+7;
namespace Dijkstra {
    const int N=::N;
    const ll MX=1ll<<55;
    ll d[N+5],dp[N+5];
    // st for start point
    // ed for end point
    // eg for edges
    typedef pair<ll,int> pli;
    ll getmin(int st,int ed,int n,vii *eg) {
        set<pli> q;
        rep(i,0,n)d[i]=MX;
        q.insert(pli(0ll,st));
        d[st]=0;dp[st]=1;

        auto upd=[&](int f,int x,ll v){
            // customized **********
            // ****************
            if(d[x]>v){
                q.erase(pli(d[x],x));
                d[x]=v;
                q.insert(pli(d[x],x));
                dp[x]=dp[f];
            } else if(d[x]==v){
                dp[x]+=dp[f];
                if(dp[x]>=mod)dp[x]-=mod;
            }
        };

        while(SZ(q)){
            ll dis;int u;
            tie(dis,u)=*q.begin(); q.erase(q.begin());
            // OUT(st,u,dis,dp[u]);
            if(u==ed)return dis;
            for(auto j:eg[u]){
                upd(u,j.x,dis+j.y);
            }
        }
        return -1;
    }
}
vii eg[N];
void add(int u,int v,int d){
    eg[u].eb(v,d);
    eg[v].eb(u,d);
}
int n;
ll calc(int st,int ed,ll *d,ll *dp){
    ll tot=Dijkstra::getmin(st,ed,n,eg);
    rep(i,0,n){
        d[i]=Dijkstra::d[i];
        dp[i]=Dijkstra::dp[i];
    }
    return tot;
}
ll sqr(ll x){
    return x*x%mod;
}
ll d[N],dp[N],d2[N],dp2[N];
int main(){
    int m,st,ed;cin>>n>>m>>st>>ed;--st;--ed;
    rep(i,0,m){
        int u,v,d;scanf("%d%d%d",&u,&v,&d);--v;--u;
        add(u,v,d);
    }
    ll tot=calc(st,ed,d,dp);calc(ed,st,d2,dp2);
    ll ans=dp[ed]*dp[ed]%mod;
    OUT(dp[ed]);
    rep(i,0,n){
        if((d[i]<<1)==tot)ans-=sqr(dp[i]*dp2[i]%mod);
        if((d[i]<<1)>=tot)continue;
        for(auto j: eg[i]){
            if(d[ed]==d[i]+j.y+d2[j.x] && (d2[j.x]<<1)<tot){
                ans-=sqr(dp[i]*dp2[j.x]%mod);
                // OUT(i,j.x,j.y,dp[i],dp2[j.x]);
            }
        }
    }
    ans%=mod;
    if(ans<0)ans+=mod;
    cout<<ans<<endl;
    return 0;
}
