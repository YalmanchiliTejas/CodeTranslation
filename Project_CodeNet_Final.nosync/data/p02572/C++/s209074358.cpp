#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define MOD 1000000007
const int N=100005;


int32_t main()
{
	int n;
	cin>>n;
	vector<int> a(n),suffix(n+1);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=n-1;i>=0;i--)
	{
		suffix[i]=(suffix[i+1]+a[i])%MOD;
	}
	int ans=0,res=0;;
	for(int i=0;i<n;i++)
	{
		ans=(a[i]*suffix[i+1])%MOD;
		res=(res+ans)%MOD;
	}
	cout<<res;
	
	
	
}
