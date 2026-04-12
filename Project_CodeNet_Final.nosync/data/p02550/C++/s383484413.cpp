// #pragma GCC optimize(2)
// #pragma G++ optimize(2)
// #pragma comment(linker,"/STACK:102400000,102400000")

#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef float fl;
typedef double dl;
typedef pair<int,int> pii;
#if (WIN32) || (WIN64) || (__WIN32) || (__WIN64) || (_WIN32) || (_WIN64) || (WINDOWS)
#define lld "%I64d"
#define llu "%I64u"
#else
#define lld "%lld"
#define llu "%llu"
#endif
#define uint(n) ((unsigned int)(n))
#define int64(n) ((long long)(n))
#define ull(n) ((unsigned long long)(n))
#define fl(n) ((float)(n))
#define dl(n) ((double)(n))
#define char(n) ((char)(n))
#define Bool(n) ((bool)(n))
#define fixpoint(n) fixed<<setprecision(n)

const int INF=1061109567;
const int NINF=-1044266559;
const int64 LINF=4557430888798830399;
const dl eps=1e-15;
#define MOD (1000000007)
#define PI (3.1415926535897932384626433832795028841971)

#define MP make_pair
#define MT make_tuple
#define All(a) (a).begin(),(a).end()
#define pall(a) (a).rbegin(),(a).rend()
#define Log(x,y) log(x)/log(y)
#define SZ(a) ((int)(a).size())
#define rep(i,n) for(int i=0;i<((int)(n));i++)
#define rep1(i,n) for(int i=1;i<=((int)(n));i++)
#define repd(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define repd1(i,n) for(int i=((int)(n));i>=1;i--)
#define repv(itr,v) for(__typeof((v).begin()) itr=(v).begin();itr!=(v).end();itr++)
#define repV(i,v) for(auto i:v)
#define repE(i,v) for(auto &i:v)
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x) MS(x,0)
#define MINF(x) MS(x,63)
#define MCP(x,y) memcpy(x,y,sizeof(y))
#define UN(v) sort(All(v)),v.erase(unique(All(v)),v.end())
#define filein(x) freopen(x,"r",stdin)
#define fileout(x) freopen(x,"w",stdout)
#define fileio(x)\
	freopen(x".in","r",stdin);\
	freopen(x".out","w",stdout)
#define filein2(filename,name) ifstream name(filename,ios::in)
#define fileout2(filename,name) ofstream name(filename,ios::out)
#define fileio2(filename,name) fstream name(filename,ios::in|ios::out)
#define sqr(x) ((x)*(x))
#define Pause system("pause")
#define Cls system("cls")
#define fs first
#define sc second
#define SF scanf
#define PF printf

const int maxn=100010;

int64 n,tot,ans;
int m,x,cnt;
vector<int> v;
map<int,int> mp;

int main()
{
	cin>>n>>x>>m;

	while(mp.count(x)==0)
	{
		v.push_back(x);
		mp[x]=cnt++;
		tot+=x;

		x=1ll*x*x%m;
	}

	if(n<=cnt)
	{
		rep(i,n) ans+=v[i];
	}
	else
	{
		int len=cnt-mp[x];
	
		int64 sum=0;
		for(int i=mp[x];i<cnt;i++) sum+=v[i];

		ans=tot;n-=cnt;
		ans+=n/len*sum;
		n%=len;

		for(int i=0;i<n;i++) ans+=v[mp[x]+i];
	}

	cout<<ans;

	return 0;
}