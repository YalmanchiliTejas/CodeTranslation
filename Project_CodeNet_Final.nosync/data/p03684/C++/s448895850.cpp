#include<bits/stdc++.h>
using namespace std;
#define m make_pair
#define I int
#define t first
#define u second
pair<I,I>x[1<<17],y[1<<17];I i,n,p[1<<17],s;
pair<I,pair<I,I>>G[2<<17];
I f(I a){return p[a]^a?p[a]=f(p[a]):a;}
main()
{
	for(cin>>n;i++<n;x[i].u=y[i].u=p[i]=i)cin>>x[i].t>>y[i].t;
	sort(x+1,x+n+1),sort(y+1,y+n+1);
	for(i=0;++i<n;)
	{
		G[i*2-1] = m(abs(x[i].t-x[i+1].t),m(x[i].u,x[i+1].u));
		G[i*2] = m(abs(y[i].t-y[i+1].t),m(y[i].u,y[i+1].u));
	}
	sort(G+1,G+n*2-1);
	for(i=0;++i<2*n-1;)
	{
		I x=G[i].u.t,y=G[i].u.u;
		if(f(x)^f(y))
		{
			s+=G[i].t;
			p[f(x)]=f(y);
		}
	}
	cout<<s<<endl;
}