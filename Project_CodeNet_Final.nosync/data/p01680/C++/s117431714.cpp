#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
	vector<int> data;
	UnionFind(int n):data(n,-1){}
	int Find(int i){
		return data[i]<0?i:(data[i]=Find(data[i]));
	}
	bool Unite(int a,int b){
		a=Find(a),b=Find(b);
		if(a==b) return false;
		if(-data[a]<-data[b]) swap(a,b);
		data[a]+=data[b];
		data[b]=a;
		return true;
	}
};

int ModPow(int a,int r,int m)
{
	long long x=1;
	for(int i=32;i--;){
		x=x*x%m;
		if(r>>i&1)
			x=x*a%m;
	}
	return x;
}

int main()
{
	constexpr int MOD=1e9+7;
	
	for(int n,m;cin>>n>>m && n|m;){
		UnionFind uf(n);
		int cc=n;
		while(m--){
			int a,b; cin>>a>>b; a--,b--;
			cc-=uf.Unite(a,b);
		}
		int res=ModPow(2,cc,MOD);
		if(cc<n) res=(res+1)%MOD;
		cout<<res<<endl;
	}
}