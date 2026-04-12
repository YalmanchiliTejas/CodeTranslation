/*   ayushkmr                 **
**   Ayush Kumar			  **
**   IIT (ISM) Dhanbad        */
/*#pragma GCC optimize("O3")
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <stdio.h>
#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define mp(x,y) make_pair((x),(y))
#define sz size()
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define lp(i,n) for(i=0; i<(n); ++i)
#define lpp(i,z,n) for(i=z; i<=(n); ++i)
#define rlp(i,n) for(i=n-1; i>=0; --i)
#define lpit(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define mset(m,v) memset(m,v,sizeof(m))
#define Abs(a,b) ((a) < (b) ? (b)-(a) : (a)-(b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define remax(a,b) (a)=max((a),(b));
#define remin(a,b) (a)=min((a),(b));
#define nu 100005
#define pnu 10
#define fnu 10
#define MOD 1000000007
#define MAX 1000000000
#define MAXL 1000000000000000000LL
#define nmod(a,b) ((a%b)+b)%b
#define LOG 11
#ifdef _WIN32
	#define pc putchar
	#define gc getchar
#else
	#define pc putchar_unlocked
	#define gc getchar_unlocked
#endif
 
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef stack<int> sti;
typedef queue<int> qi;
typedef pair<int,int> ii;
typedef pair<ll,ii> iii;
typedef vector<iii> viii;
typedef vector<ii> vii;
typedef unordered_map<int,int> ump;
typedef map<int,int> mpp;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline int in(){int N=0;register char c=gc();while( c < 48 || c > 57 ){c=gc();}while(c>47 && c< 58){N = (N << 3) + (N << 1) + (c - 48);c=gc();}return N;}
inline ll inl(){ll N=0;register char c=gc();while( c < 48 || c > 57 ){c=gc();}while(c>47 && c< 58){N = (N << 3) + (N << 1) + (c - 48);c=gc();}return N;}
inline int inp(){int N=0,sign=1;register char c=gc();while( c < 48 || c > 57 ){if(c=='-')sign=0; c=gc();}while(c>47 && c< 58){N = (N << 3) + (N << 1) + (c - 48);c=gc();}return (sign?N:(-N));}
inline ll inpl(){ll N=0,sign=1;register char c=gc();while( c < 48 || c > 57 ){if(c=='-')sign=0; c=gc();}while(c>47 && c< 58){N = (N << 3) + (N << 1) + (c - 48);c=gc();}return (sign?N:(-N));}
inline bool inb(){char c=gc();while( c < 48 || c > 57 ){c=gc();}return(c=='0'?0:1);}
inline ll ModP(ll b, ll e) {b %= MOD;ll r = 1;while (e>0) {if (e & 1) r = (r * b) % MOD;b = (b * b) % MOD;e >>= 1;}return r;}
bool pri[pnu]={1,1,0,0};
vi prm;
inline void prime_init() {int i,j;for(i=3;i*i<pnu;i+=2){if(!pri[i]){for(j=i*i;j<=pnu;j+=2*i){pri[j]=1;}}}}
inline void prime_asgn() {int i;prm.pb(2);for(i=3;i<pnu;i+=2)if(!pri[i])prm.pb(i);}
inline bool prime_check(ll i) { if(i==1) return 0; if(i<4) return 1; if(i&1) { if(i<pnu) {if(!pri[i]) return 1;else return 0; } else { int j,x; for(j=1;((x=prm[j])*x)<=i;j++) { if(!(i%x)) return 0; } return 1; } } else return 0; }
inline bool rngprm_check(int i) {if(i==1) return 0;if(i<4) return 1;if(i&1) {if(!pri[i]) return 1;else return 0;}else return 0;}
inline int npf(ll s){int j,x;int c; for(c=j=0;((x=prm[j])*prm[j])<=s;j++){ if(!(s%x)){ c++; while(!(s%x)) { s/=x; }}} if(s>1) c++; return(c); }
inline int nf(ll s) { if(s==1) return 1; int j,x,f=1; int c=1; for(j=0;((x=prm[j])*prm[j])<=s;c=1,j++) { if(!(s%x)){ while(!(s%x)){ s/=x; c++; } f=f*c; }} if(s>1) { f=f<<1;} return(f);}
vii nfa;
inline void nfx(ll s) {nfa.clear();if(s==1) return;int j,x,c=0;for(j=0;((x=prm[j])*prm[j])<=s;c=0,j++) { if(!(s%x)){while(!(s%x)){ s/=x; c++;} nfa.pb(mp(x,c)); }} if(s>1) {nfa.pb(mp(s,1));}}
ll fc[fnu];
inline ll InverseEuler(ll n){ return ModP(n,MOD-2); }
inline ll nCr(int n, int r){ if(r>n) return 0; return (fc[n]*((InverseEuler(fc[r]) * InverseEuler(fc[n-r])) % MOD)) % MOD;}
inline void facs(){ fc[0]=fc[1]=1; for(ll i=2;i<fnu;i++){ fc[i]=(i*fc[i-1])%MOD; } }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vii l,xx,yy;
viii d;
int size[nu],root[nu];
ll ans=0;
inline void init(int n)
    {
    for(int i=0;i<n;i++)
        {
        size[i]=1;
        root[i]=i;
    }
}
inline int findit(int x)
    {
    while(x!=root[x])
        {
        root[x]=root[root[x]];
        x=root[x];
    }
    return x;
}
inline void unionit(int x,int y,ll sm)
    {
    int p,q;
    if(x==y)
        return;
    p=findit(x);
    q=findit(y);
    if(p==q)
        return;
        else
        {
            ans+=sm;
        if(size[p]>size[q])
            {
            root[q]=p;
            size[p]+=size[q];
        }
            else if(size[q]>size[p])
                {
                root[p]=q;
                size[q]+=size[p];
            }
            else
                {
                root[q]=p;
                size[p]+=size[q];
            }
    }
}
int main()
{
	//ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);freopen ("in.txt","r",stdin); freopen ("out.txt","w",stdout);
    ll n=in(),i,j,s,x,y;
    init(n+2);
    lp(i,n)
    {
        x=in();
        y=in();
        l.pb(mp(x,y));
        xx.pb(mp(x,i));
        yy.pb(mp(y,i));
    }
    sort(all(xx));
    sort(all(yy));
    lp(i,n-1)
    {
        j=xx[i+1].ff-xx[i].ff;
        d.pb(mp(j,mp(xx[i+1].ss,xx[i].ss)));
        j=yy[i+1].ff-yy[i].ff;
        d.pb(mp(j,mp(yy[i+1].ss,yy[i].ss)));
    }
    sort(all(d));
    for(auto it : d)
    {
        j=it.ff;
        x=it.ss.ff;
        y=it.ss.ss;
        unionit(x,y,j);
    }
    cout<<ans;
	return 0;
}