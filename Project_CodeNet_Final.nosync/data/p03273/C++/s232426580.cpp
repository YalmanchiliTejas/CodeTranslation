#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%lld",&n)
#define pr(n) printf("%d",n)
#define prl(n) printf("%lld",n)
#define nl printf("\n")
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
ll pow1(ll a, ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
		{
			ans=ans*a;
		}
		a=a*a;
		b=b>>1;
	}
	return ans;
}
int main()
{
	int n,m,i,j;
	cin>>n>>m;
	vector<string> v;
	string s;
	for(i=0;i<n;i++)
	{
		cin>>s;
		v.pb(s);
	}
	int arr1[n],arr2[m];
	memset(arr1,0,sizeof(arr1));
	memset(arr2,0,sizeof(arr2));
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			if(v[i][j] == '#')
			{
				arr1[i] = 1;
				break;
			}
	}
	for(j=0;j<m;j++)
	{
		for(i=0;i<n;i++)
			if(v[i][j] == '#')
			{
				arr2[j] = 1;
				break;
			}
	}
	int f = 0;
	for(i=0;i<n;i++)
	{
		f = 0;
		for(j=0;j<m;j++)
			if(arr1[i] && arr2[j])
			{
				f = 1;
				cout<<v[i][j];
			}
		if(f==1)
			cout<<endl;
	}
	return 0;
}