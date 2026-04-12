/*
	Name:
	Author: xiaruize
	Date:
*/

#include<algorithm>
#include<bitset>
#include<cctype>
#include<cerrno>
#include<clocale>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<limits>
#include<list>
#include<map>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<utility>
#include<vector>
#include<cwchar>
#include<cwctype>
using namespace std;
#define ull unsigned long long
#define MOD 1000000007
#define ALL(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long
#define form(i,j,n) for(int i=int(j);i<=int(n);i++)
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define pis pair<int,string>
#define sec second
#define sz(a) int((a).size())

inline int read()
{
    char ch=getchar();
    int x=0,f=1;
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
    return x*f;
}
#define int ll
int a[200005];
int dp[200005];
int sum[200005];

signed main()
{
 	ios::sync_with_stdio(false);
	cin.tie(0);
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i!=1)
			sum[i]=sum[i-2]+a[i];
		else
			sum[1]=a[1];
	}
	for(int i=2;i<=n;i++)
	{
		if(i%2)
			dp[i]=max(dp[i-2]+a[i],dp[i-1]);
		else
			dp[i]=max(dp[i-2]+a[i],sum[i-1]);
	}
	cout<<dp[n]<<endl;
	return 0;
}