//long time no ac
#include <bits/stdc++.h>
using namespace std;

#define 	ll				long long
#define 	vi				vector<int>
#define		rep(i,n) 		for(i=0;i<n;i++)
#define		repe(i,I1,I2) 	for(i=I1;i<I2;i++)
#define		INF  			1e9 + 7
#define		pb  			push_back
#define		mp  			make_pair
#define		endl			'\n'
#define 	mod				1000000007


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k,t,c=0,i,a,b,x,y;
	t=1;
	//cin>>t;
	
	while(t--)
	{
		cin>>a>>b>>c>>x>>y;
		n=2*max(x,y)*c;
		k=2*min(x,y)*c;
		k+=( (x>y)?((x-y)*a):((y-x)*b) );
		i=a*x+b*y;
		cout<<min(min(n,k),i);
		if(t!=0)
	   		cout<<"\n";
	}
	return 0;
}