#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	int a,b,c,n,m,ans,sum;
	cin>>a>>b>>c>>n>>m;
	ans=a*n+b*m;
	sum=a*n+b*m;
	for(int i=1;i<=max(n,m);i++)
	{
		if(i<=min(n,m))ans=min(ans,sum-a*i-b*i+2*c*i);
		else if(n>=m)ans=min(ans,sum-a*i-b*m+2*c*i);
		else ans=min(ans,sum-a*n-b*i+2*c*i);
	}
	cout<<ans<<endl;
	return 0;
}