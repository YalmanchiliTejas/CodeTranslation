#include<iostream>
using namespace std;
#include<vector>
struct UF{
	int n;
	vector<int>parent,rank;
	UF(int n_=0):n(n_),parent(n_),rank(n_,1)
	{
		for(int i=0;i<n_;i++)parent[i]=i;
	}
	int find(int a){return parent[a]!=a?parent[a]=find(parent[a]):a;}
	bool same(int a,int b){return find(a)==find(b);}
	bool unite(int a,int b)
	{
		a=find(a),b=find(b);
		if(a==b)return false;
		if(rank[a]<rank[b])
		{
			parent[a]=b;
			rank[b]+=rank[a];
		}
		else
		{
			parent[b]=a;
			rank[a]+=rank[b];
		}
		return true;
	}
	int size(int a){return rank[find(a)];}
};
int N,M;
long mod=1e9+7;
long power(long a,long b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
main()
{
	while(cin>>N>>M,N)
	{
		UF uf(N);
		int cnt=N;
		for(int i=0;i<M;i++)
		{
			int u,v;cin>>u>>v;
			u--,v--;
			if(uf.unite(u,v))cnt--;
		}
		long ans=power(2,cnt);
		if(M!=0)ans=(ans+1)%mod;
		cout<<ans<<endl;
	}
}

