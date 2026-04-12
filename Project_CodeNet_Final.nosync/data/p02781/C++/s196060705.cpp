#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define mkp make_pair
#define in insert
#define er erase
#define fd find
#define fr first
#define sc second
typedef long long ll;
typedef long double ld;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll llinf=(1LL<<62);
const int inf=(1<<30);
const int nmax=1e5+50;
const int mod=1e9+7;
using namespace std;
int k,i,t,j,p,n;
ll f[105][5][2];
string s;
char c[105];
int main()
{
	//freopen("sol.in","r",stdin);
	//freopen("sol.out","w",stdout);
	//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
	cin>>s>>k;
	n=(int)s.size();
	for(i=1;i<=n;i++)c[i]=s[i-1];
	f[0][0][1]=1;
	for(i=0;i<n;i++)
	{
		for(t='0';t<='9';t++)
		{
			for(j=0;j<2;j++)
			{
				if(j && t>c[i+1])continue;
				for(p=0;p<=k;p++)
				{
					if(p-(t!='0')<0)continue;
					f[i+1][p][j&(c[i+1]==t)]+=f[i][p-(t!='0')][j];
				}
			}
		}
	}
	cout<<f[n][k][0]+f[n][k][1]<<endl;
	return 0;
}
