#include <bits/stdc++.h>
#define int LL
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,b,a) for(int i=b;i>=a;i--)
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Forenska(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define GREATER(x) x,vector<x>,greater<x>
#define randIn(L,R) (((LL)rand()*rand())%(R-L)+L)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;
typedef vector<int> vec;
typedef vector<LL> vecL;
typedef vector<pii> vecP;
typedef vector<pLL> vecPL;
typedef vector<string> vecS;
typedef vector<vec> mat;
typedef complex<double> point;
const long double PI=3.14159265358979323846264338327950288419716939937510582097;
const LL INFLL=0x3f3f3f3f3f3f3f3f;
const int INF=0x3f3f3f3f;
const long double EPS=1e-10;
int read()
{
    int x=0;
    char ch=' ';
    bool flag=false;
    while(ch<'0' || ch>'9')
    {
        if(ch=='-')flag=true;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return flag?-x:x;
}
const int MAX_N=55;
LL L[MAX_N];
void init()
{
	L[0]=1;
	For(i,1,50)
	{
		L[i]=2*L[i-1]+3;
	}
}
map <pLL,int> dp;
int dfs(int k,LL X)
{
	if(X<=0)return 0;
	if(k==0)return 1;
	if(dp.count(mp(k,X)))return dp[mp(k,X)];
	int res=0;
	res+=dfs(k-1,min(X-1,L[k-1]));
	if(X-1>L[k-1])res++;
	res+=dfs(k-1,min(X-L[k-1]-2,L[k-1]));
//	cout<<"dfs("<<k<<","<<X<<")"<<endl;
//	cout<<res<<endl;
	dp[mp(k,X)]=res;
	return res;
}
signed main()
{
	init();
	LL n,X;
	cin>>n>>X;
	cout<<dfs(n,X)<<endl;
	return 0;
}

