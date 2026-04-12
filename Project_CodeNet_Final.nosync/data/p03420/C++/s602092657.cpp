#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define rep(n) for(int i=0;i<n;i+=1)
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    ll ans = 0;
    for(int b = k+1; b <= n; b++)
    {
    	int range = b-k;
    	int xmin = (n-(k))/b;
    	int xmax = (n-(b-1))/b;
    	// printf("%d %d\n",xmin,xmax );
    	if(xmin==xmax)
    	{
	    	ans += range*(xmax+1);
    	}
    	else
    	{
	    	ans += range*(xmax+1);
    		// int l = k;
    		// int r = b-1;
    		// int m=0;
    		// while(l<=r)
    		// {
    		// 	m = l+(r-l)/2;
    		// 	if(b*xmin+m == n)
    		// 	{
    		// 		l = m;
    		// 		break;
    		// 	}
    		// 	else if(b*xmin+m < n)
    		// 		l = m+1;
    		// 	else
    		// 		r = m-1;
    		// }
    		// printf("ans bs%lld %d\n",ans,n%b );
    		// if(k)
    		ans+=max({0,(n%b)-k+1});
    	}
    	if(k==0)
    	{
    		ans-=1;
    		
    	}
    // printf("b==%d\n",b );	
    }
    cout<<ans<<endl;
    return 0;

}