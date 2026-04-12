#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
int const M=3e5+10,inf=1e9+10,mod=1e9+7;
int a,n,b;
int ans[M];
main()
{
	int n,k;
	cin>>n>>k;
	if(k==0)return cout<<n*n,0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i<=k)continue;
		int tmp=n/i;
		tmp--;
		ans+=tmp*(i-k);
		int hlp=(tmp+1)*i;
		//cout<<hlp<<endl;
		if(hlp+k>n)continue;
		hlp+=k;
		ans+=n-hlp+1;
	}
	int tmp=n-k;
	cout<<ans+(tmp*(tmp+1))/2;
}