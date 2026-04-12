#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

#define fast ios_base::sync_with_stdio(0),cin.tie(0)
#define temp template<typename T>
#define debug(x) cerr<<"Line "<<__LINE__<<": "<<#x<<" = "<<x<<'\n'
#define itr(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define rep(i,a,b) for(int i=a;i<=(int)b;i++)
#define repr(i,a,b) for(int i=a;i>=(int)b;i--)
#define cas(n) printf("Case %d:",(int)n)
#define mem(x,v) memset(x,v,sizeof(x))
#define read(x) freopen(x,"r",stdin)
#define write(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define aut(x,v) for(auto &x:v)
#define ini(n) scanf("%d",&n)
#define inl(n) scanf("%lld",&n)
#define ind(n) scanf("%lf",&n)
#define ins(n) scanf("%s",n)
#define insn(n) scanf(" %[^\n]",n)
#define outi(n) printf("%d",(int)n)
#define outl(n) printf("%lld",(LL)n)
#define outd(n,p) printf("%.*lf",p,(double)n)
#define outs(n) printf("%s",n)
#define sz(x) (int)x.size()
#define nl printf("\n")
#define sp printf(" ")
#define pb push_back
#define mp make_pair
#define xx first
#define yy second

const int inf=0x3f3f3f3f;
const int mod=1000000007;
const int mx=100005;
const LL  infL=0xf3f3f3f3f3f3f3f;
const double eps=1e-9;
const double pi=acos(-1.0);

int main()
{
    //read("in.txt"),write("out.txt");
    int n;
    ini(n);
    if(n==3||n==5||n==7)
        outs("YES"),nl;
    else
        outs("NO"),nl;
    return 0;
}
