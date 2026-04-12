#include<bits/stdc++.h>
using namespace std;

main(int argc, char const *argv[])
{
	int n,a,b,c,x;
	while(cin>>n>>a>>b>>c>>x,n)
	{
		int y[n+1];
		for (int i = 0; i < n; ++i) cin>>y[i];
		y[n]=-1;
		int now=0;
		if(x==y[0]) ++now;
		if(n==1&&now==1)
		{
			cout<<"0\n";
			continue;
		}
		int i;
		for (i = 0; i < 10000; ++i)
		{
			x=(a*x+b)%c;
			if(x==y[now]) ++now;
			if(now==n) break;
		}
		if(now==n) cout<<i+1<<endl;
		else cout<<"-1\n";
	}
	return 0;
}
