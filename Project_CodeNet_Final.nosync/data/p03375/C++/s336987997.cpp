//Create Time: 2018-04-27 22:14:20
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
typedef pair<long long, long long> pll;
namespace Factor{
    // long long powmod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
    const int N=1010000;
    int tot,top,size;
    int prm[N],least_prm[N],_phi[N];
    long long stk_p[111],stk_k[111];
    void prime_table(){
        int i,j,t1;
        tot=0;
        _phi[1]=1;
		for(i=1;i<=size;i++) least_prm[i]=i;
		for(i=2;i<=size;i++){
			if(least_prm[i]==i) prm[tot++]=i,_phi[i]=i-1;
			for(j=0;j<tot && (t1=prm[j]*i)<=size;j++){
				least_prm[t1]=prm[j];
				if(i%prm[j]==0){
                    _phi[i*prm[j]] = _phi[i]*prm[j]; break;
                }else{
                    _phi[i*prm[j]] = _phi[i]*(prm[j]-1);
                }
			}
		}
    }
    void _factor(long long n){
        int i,t;
        for(i=0;i<tot && n>size && 1ll*prm[i]*prm[i]<=n;++i){
            if(n%prm[i]==0){
                stk_k[top]=0;
                stk_p[top]=prm[i];
                while(n%prm[i]==0){
                    stk_k[top]++;
                    n/=prm[i];
                }
                ++top;
            }
        }
        if(n>size){
            stk_k[top]=1;
            stk_p[top++]=n;
            return;
        }
        while(n>1){
            t=least_prm[n];
            if(!top || stk_p[top-1]!=t){
                stk_k[top]=1;
                stk_p[top++]=t;
            }else ++stk_k[top-1];
            n/=t;
        }
    }
    bool is_prime(long long p){
        if(p==1)return 0;
        if(p<=size)return least_prm[p]==p;
        for(int i=0;i<tot && p>size && 1ll*prm[i]*prm[i]<=p;++i){
            if(p%prm[i]==0)return 0;
        }
        return 1;
    }
    /****************************************************/
    // return prime num
    int init(int n=N-5){
        size=n;
        prime_table();
        return tot;
    }
    vector<pll> factorG(long long n){
        top=0;
        _factor(n);
        vector<pll> d;
        for(int i=0;i<top;++i)d.pb(pll(stk_p[i],stk_k[i]));
        return d;
    }
    long long phi(long long x){
        if(x<=size)return _phi[x];
        vector<pll> d=factorG(x);
        for(auto p:d) x=x/p.x*(p.x-1);
        return x;
    }
    bool is_primitive(long long a,long long p){
        if(a>=p)return 0;
        assert(is_prime(p));
        vector<pll> d=factorG(p-1);
        for(auto i:d) if(powmod(a,(p-1)/i.x,p)==1)return 0;
        return 1;
    }
}
template<int sz> struct Comb{
    ll mod;
    ll *fac, *ifac;
    ll mem_fac[sz+5],mem_ifac[sz+5];

    // long long powmod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}

    Comb(ll _mod,ll *fa=0,ll *ifa=0){
        mod=_mod;
        fac=fa?fa:mem_fac;
        ifac=ifa?ifa:mem_ifac;
        fac[0]=ifac[0]=1;
        for(int i=1;i<sz;++i){
            fac[i]=i*fac[i-1]%mod;
            ifac[i]=powmod(fac[i],mod-2,mod);
        }
    }
    ll C(ll n,ll m){  // n >= m
        if(n<m)return 0;
        return (fac[n]*ifac[m]%mod)*ifac[n-m]%mod;
    }
    ll A(ll n,ll m){
        if(n<m)return 0;
        return fac[n]*ifac[n-m]%mod;
    }
};

const int N=3333;
ll fac[N],fnv[N];

int n;
ll mod,p,s[N][N],sum[N];
ll pow22(int x){
    ll t=powmod(2,x,p)+p;
    if(x>=40)return powmod(2,t,mod);
    return powmod(2,min(1ll<<x,t),mod);
}
int main(){
    cin>>n>>mod;
    Comb<N> comb(mod,fac,fnv);
    Factor::init();
    p=Factor::phi(mod);
    OUT(p);
    s[1][1]=1;
    rep(i,2,n+2){
        s[i][i]=s[i][1]=1;
        rep(j,2,i)s[i][j]=(s[i-1][j-1]+j*s[i-1][j])%mod;
    }
    ll ans=0;
    rep(i,0,n+1){
        sum[i]=0;
        rep(j,1,i+2)sum[i]+=s[i+1][j]*powmod(2,(j-1)*(n-i),mod)%mod;
        sum[i]%=mod;
        sum[i]=sum[i]*pow22(n-i)%mod;
        ans+=((i&1?-1ll:1ll) * comb.C(n,i) * sum[i]) % mod;
        // OUT(i,sum[i],ans,pow22(n-i));
    }
    ans%=mod;
    if(ans<0)ans+=mod;
    cout<<ans<<endl;
    return 0;
}
