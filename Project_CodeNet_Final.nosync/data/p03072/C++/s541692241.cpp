#include<bits/stdc++.h>
#define int long long 
#define LL long long 
#define LD long double
#define PI 3.14159265358979323846
#define MOD ((LL)1e9+7)
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;




	
int32_t main()
{
	int n,ans=0,mx=0;cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		if(mx<=x)
		{
			ans++;
			mx=x;
		}
	}
	cout<<ans<<endl;
}
				
				   
	

	
