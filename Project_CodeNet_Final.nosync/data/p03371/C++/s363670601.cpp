#include <bits/stdc++.h>
 
#define REP(i,n) for(int i=0;i<n;i++)
 
using namespace std;
 
 
int main()
{
	int a,b,c,x,y,ans;
	cin>>a>>b>>c>>x>>y;
	if(a+b>=c*2){
		int cost=min(x,y);
		x-=cost,y-=cost;
		ans+=c*2*cost;
		if(a*x+b*y>c*2*max(x,y)){
			ans+=c*2*max(x,y);
		}
		else{
			ans+=a*x+b*y;
		}
	}
	else{
		ans+=a*x+b*y;
	}
	cout<<ans<<endl;
	}
	