#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define ld long double
#define F first
#define S second
int const M=2e5+10,mod=1e9+7,inf=1e9+10;
int n,a[M],ans[M];
pii cur[M];
main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>cur[i].F,cur[i].S=i;
	sort(cur+1,cur+n+1);
	for(int i=1;i<=n;i++)
	{
		if(i<=n/2)ans[cur[i].S]=cur[n/2+1].F;
		else ans[cur[i].S]=cur[n/2].F;
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<"\n";
}