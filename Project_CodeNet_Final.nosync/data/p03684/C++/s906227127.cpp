#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,pair<int,int> > >points;
vector<pair<int,pair<int,int> > > edge;
int par[100005];
bool cmp(pair<int,pair<int,int> > &a,pair<int,pair<int,int> > &b ){
	return a.second.first<b.second.first;
}
bool cmp2(pair<int,pair<int,int> > &a,pair<int,pair<int,int> > &b ){
	return a.second.second<b.second.second;
}
void init(){
	for(int i=1;i<=100000;i++){
		par[i]=i;
	}
}
int find(int i){
	if(par[i]==i) return par[i];
	return par[i]=find(par[i]);
}
void dsu(int i,int j){
	par[find(i)]=find(j);
}
bool same(int i,int j){
	return find(i)==find(j);
}
signed main(){
//	freopen("plantree.inp","w",stdin);
//	freopen("plantree.out","r",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		points.push_back(make_pair(i,make_pair(x,y)));
	}	
	init();
	sort(points.begin(),points.end(),cmp);
	for(int i=1;i<points.size();i++){
		edge.push_back(make_pair(points[i].second.first-points[i-1].second.first,make_pair(points[i].first,points[i-1].first)));
	}
	sort(points.begin(),points.end(),cmp2);
	for(int i=1;i<points.size();i++){
		edge.push_back(make_pair(points[i].second.second-points[i-1].second.second,make_pair(points[i].first,points[i-1].first)));
	}
	sort(edge.begin(),edge.end());
	int ans=0;
	
	for(int i=0;i<edge.size();i++){
		if(!same(edge[i].second.second,edge[i].second.first)){
			ans+=edge[i].first;
			dsu(edge[i].second.second,edge[i].second.first);
		}
	}
	cout<<ans;
}