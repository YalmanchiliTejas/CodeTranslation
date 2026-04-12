#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct lazysegtree{
	int n;
	vector<long>dat,lazy;
	lazysegtree(int n_)
	{
		n=1;
		while(n<n_)n<<=1;
		dat.assign(2*n-1,0);
		lazy.assign(2*n-1,0);
	}
	void eval(int i,int l,int r)
	{
		if(lazy[i])
		{
			dat[i]+=lazy[i];
			if(r-l>1)
			{
				lazy[2*i+1]+=lazy[i];
				lazy[2*i+2]+=lazy[i];
			}
			lazy[i]=0;
		}
	}
	void update(int a,int b,long x,int k=0,int l=0,int r=-1)//[a,b)
	{
		if(r<0)r=n;
		eval(k,l,r);
		if(b<=l||r<=a)return;
		else if(a<=l&&r<=b)
		{
			lazy[k]+=x;
			eval(k,l,r);
		}
		else
		{
			update(a,b,x,2*k+1,l,(l+r)/2);
			update(a,b,x,2*k+2,(l+r)/2,r);
			dat[k]=max(dat[2*k+1],dat[2*k+2]);
		}
	}
	long query(int a,int b,int k=0,int l=0,int r=-1)//[a,b)
	{
		if(r<0)r=n;
		eval(k,l,r);
		if(b<=l||r<=a)return 0;
		else if(a<=l&&r<=b)return dat[k];
		else return max(
			query(a,b,2*k+1,l,(l+r)/2),
			query(a,b,2*k+2,(l+r)/2,r)
		);
	}
};
int n,m;
vector<pair<int,int> >P[2<<17];
main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int l,r,a;cin>>l>>r>>a;
		P[r].push_back(make_pair(l,a));
	}
	lazysegtree dp(n+1);
	for(int i=1;i<=n;i++)
	{
		dp.update(i,i+1,dp.query(0,i));
		for(int j=0;j<P[i].size();j++)
		{
			dp.update(P[i][j].first,i+1,P[i][j].second);
		}
	}
	cout<<dp.query(0,n+1)<<endl;
}