#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int n;
vector<int> par;
vector<int> size;
struct gg{
	long long x,y;
	int id;
}a[100005];
bool cmp1(const gg &q,const gg &w){
    return q.x<w.x;
}
bool cmp2(const gg &q,const gg &w){
    return q.y<w.y;
}
void init(int n){
	size.assign(n+1,1);
	par.assign(n+1,0);
	for(int i=0;i<=n;i++){
		par[i]=i;
	}
}
int find(int x){
	if(par[x]==x) return par[x];
	par[x]=find(par[x]);
	return par[x];
}
bool issameset(int x,int y){
	return find(x)==find(y);
}
void Union(int x,int y){
	if(!issameset(x,y)){
		size[find(y)]+=size[find(x)];
		par[find(x)]=find(y);
	}
}
int main(){
	cin>>n;
	init(n);
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].id=i;
	}
	vector<pair<long long,ii> > edgelist;
	sort(a,a+n,cmp1);
	for(int i=1;i<n;i++){
		edgelist.push_back(make_pair(a[i].x-a[i-1].x,ii(a[i].id,a[i-1].id)));
	}
	sort(a,a+n,cmp2);
	for(int i=1;i<n;i++){
		edgelist.push_back(make_pair(a[i].y-a[i-1].y,ii(a[i].id,a[i-1].id)));
	}
	sort(edgelist.begin(),edgelist.end());
	long long mst=0;
	for(int i=0;i<edgelist.size();i++){
		pair<long long,ii> front=edgelist[i];
		if(!issameset(front.second.first,front.second.second)){
			Union(front.second.first,front.second.second);
			mst+=front.first;
		}
	}
	cout<<mst;
}