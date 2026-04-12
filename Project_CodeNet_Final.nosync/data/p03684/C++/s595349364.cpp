#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(a,k)     ((bool)(a&(1<<(k))))
#define    bitOff(a,k)       (a&(~(1<<(k))))
#define    bitOn(a,k)        (a|(1<<(k)))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    iseq(a,b)         (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))
#define    UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef mamun
     #define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************
int t,n,m;
vector<pii> x,y;
#define MAXN 300005
struct edge
{
	int u,v,w;
	bool operator < ( const edge& p ) const
	{
		return w < p.w;
	}
};
int pr[MAXN];
int tot = 0;
vector<edge> e;
int find(int r)
{
    if(pr[r]==r) return r;
    return pr[r]=find(pr[r]);
}
ll mst(int n)
{
	sort(e.begin(),e.end());
	for(int i=1;i<=n;i++)pr[i]=i;

	int count=0;
	ll s=0;
	for(int i=0;i<(int)e.size();i++)
	{
		int u=find(e[i].u);
		int v=find(e[i].v);
		if(u!=v)
		{
			pr[u]=v;
			count++;
			s+=e[i].w;
			if(count == n-1) break;
		}
	}
	return s;
}
void addEdge(int u,int v,int cost)
{
    edge get;
    get.u = u;
    get.v = v;
    get.w = cost;
    e.push_back(get);
}

map<pii,int> mp;

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getI(n))
    {
        tot = 0;
        mp.clear();
        x.clear();
        y.clear();
        e.clear();
        tot = 0;
        rep(i,n)
        {
            int a,b;
            getII(a,b);
//            debug(a,b)
//            if(mp[pii(a,b)])continue;
//            mp[pii(a,b)] = 1;
            x.PB(pii(a,i));
            y.PB(pii(b,i));
            tot++;
        }
        sort(ALL(x));
        sort(ALL(y));
        repI(i,x.size())
        {
            if(i)
            {
                int v = x[i-1].ss;
                int cost = abs(x[i-1].ff - x[i].ff);
                addEdge(x[i].ss, v, cost);
            }
            if(i+1<x.size())
            {
                int v = x[i+1].ss;
                int cost = abs(x[i+1].ff - x[i].ff);
                addEdge(x[i].ss, v, cost);
            }
        }
        repI(i,y.size())
        {
            if(i)
            {
                int v = y[i-1].ss;
                int cost = abs(y[i-1].ff - y[i].ff);
                addEdge(y[i].ss, v, cost);
            }
            if(i+1<y.size())
            {
                int v = y[i+1].ss;
                int cost = abs(y[i+1].ff - y[i].ff);
                addEdge(y[i].ss, v, cost);
            }
        }
        printf("%lld\n",mst(tot));

    }

    return 0;
}

