#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<math.h>
#include<utility> 
using namespace std;
int n;
int x[100032],y[100032];
int fa[100032],rk[100032];
pair<int,int> dot[100032];
vector<pair<long long,pair<int,int> > > ve;
long long ans;
int GetFather(int x){
	while(x!=fa[x]) x=fa[x];
	return x;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<n;i++){
		dot[i].first=x[i];
		dot[i].second=i;
	}
	sort(dot,dot+n);
	for(int i=0;i<n-1;i++){
		int u=dot[i].second;
		int v=dot[i+1].second;
		int w=min(abs(x[u]-x[v]),abs(y[u]-y[v]));
		ve.push_back(make_pair(w,make_pair(u,v))); 
	}
	for(int i=0;i<n;i++){
		dot[i].first=y[i];
		dot[i].second=i;
	}
	sort(dot,dot+n);
	for(int i=0;i<n-1;i++){
		int u=dot[i].second;
		int v=dot[i+1].second;
		int w=min(abs(x[u]-x[v]),abs(y[u]-y[v]));
		ve.push_back(make_pair(w,make_pair(u,v))); 
	}
	ve.erase(unique(ve.begin(),ve.end()),ve.end()); 
	sort(ve.begin(),ve.end());
	int s=0;
	for(int i=1;i<=n;i++) fa[i]=i,rk[i]=1;
	for(int i=0;i<ve.size()&&s<n;i++){
		int u=ve[i].second.first;
		int v=ve[i].second.second;
		int uf=GetFather(u);
		int vf=GetFather(v);
		if(uf==vf) continue;
		s++;
		if(rk[uf]<rk[vf]) fa[uf]=vf;
		else if(rk[uf]>rk[vf]) fa[vf]=uf;
		else{
			fa[uf]=vf;
			rk[vf]++;
		}
		ans+=ve[i].first;
	} 
	cout<<ans<<endl;
	return 0;
}