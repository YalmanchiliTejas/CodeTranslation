#include<bits/stdc++.h>

using namespace std;
int g[100005];
int x[100005][2];
int u[100005];
vector<pair<long long,pair<int,int> > >v;
int FIND(int p){
	if(g[p]==p)return p;
	else return g[p]=FIND(g[p]);
}
void UNION(int p,int q){
	g[FIND(p)]=FIND(q);
}
bool cmp1(int a,int b){
	return x[a][0]<x[b][0];
}
bool cmp2(int a,int b){
	return x[a][1]<x[b][1];
}
int main(){
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)cin>>x[i][0]>>x[i][1]; 
	for(int i=1;i<=n;i++)u[i]=g[i]=i;
	sort(u+1,u+n+1,cmp1);
	for(int i=1;i<n;i++){
		v.push_back(make_pair(x[u[i+1]][0]-x[u[i]][0],make_pair(u[i],u[i+1])));
	}
	sort(u+1,u+n+1,cmp2);
	for(int i=1;i<n;i++){
		v.push_back(make_pair(x[u[i+1]][1]-x[u[i]][1],make_pair(u[i],u[i+1])));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		if(FIND(v[i].second.first)==FIND(v[i].second.second))continue;
		ans+=v[i].first;
		UNION(v[i].second.first,v[i].second.second);
	}
	cout<<ans;
	return 0;
}