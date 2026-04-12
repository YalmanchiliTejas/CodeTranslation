#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define For(i,n) for(long long i=0;i<n;i++)
#define Fre(i,a,b) for(long long i = a; i < b; i++)
#define sf(n) scanf("%d", &n)
#define sff(a,b) scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pfn(n) prlong longf("%d\n", n)
#define pfs(n) prlong longf("%d ", n)
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define READ freopen("in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)
#define sz size()
#define number_of_digit(n) __builtin_ffs(n);
#define ll long long
#define T long long
ll a[3005][3005],b[3005];
ll sum1,sum2;
ll ans;
bool is;
ll solve(int x,int y)
{
	if(x>y)
	{
		return 0;
	}
	if(a[x][y]!=LONG_LONG_MIN)return a[x][y];
	if(is)
	{
		is=false;
		ll g=solve(x+1,y);
		is=false;
		g=max(g+b[x],solve(x,y-1)+b[y]);
		return a[x][y]=g;
	}
	else
	{
		is=true;
		ll g=solve(x+1,y);
		is=true;
		g=min(g-b[x],solve(x,y-1)-b[y]);
		return a[x][y]=g;
	}
 
}
int main()
{
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
 
  	int n,k;
  	cin>>n;
  	For(i,n)cin>>b[i+1];
  	is=true;
  	sum1=0;
  	sum2=0;
  	For(i,n+1)For(j,n+1)a[i][j]=LONG_LONG_MIN;
  	cout<<solve(1,n)<<endl;
	return 0;
}