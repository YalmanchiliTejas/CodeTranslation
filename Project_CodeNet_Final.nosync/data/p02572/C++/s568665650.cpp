#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
#define ld long double
#define pii pair<int,int>
#define vvi vector<vector<int> >
#define vpi vector<pii>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define INF 0x7fffffff
#define LINF 0x7fffffffffffffff
#define MOD 1000000007
#define lowbit(x) x&(-x)
#define HS 173LL
#define int long long
using namespace std;
int read()
{
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))
		ch=getchar();
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
const int maxn=2e5+10,mod=1e9+7;
int n,a[maxn],sum=0,ans=0;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]%=mod;
	}
	for(int i=1;i<=n;i++)
	{
		sum=(sum+a[i])%mod;
	}
	for(int i=1;i<n;i++)
	{
		sum=(sum-a[i]+mod)%mod;
		ans+=(a[i]*sum%mod);
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}