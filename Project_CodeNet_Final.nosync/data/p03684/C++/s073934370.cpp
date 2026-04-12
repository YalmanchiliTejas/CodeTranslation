#include<bits/stdc++.h>

using namespace std;
int g[100005],px[100005],py[100005];
pair<int,int>sx[100005],sy[100005];
int FIND(int x){
	if(g[x]==x)return x;
	else return g[x]=FIND(g[x]);
}
int value(int x,int y){
	x=FIND(x);
	y=FIND(y);
	if(x==y)return 0;
	g[x]=y;
return 1;
}
int op(int x,int y){
	return min(abs(px[x]-px[y]),abs(py[x]-py[y]));
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>px[i]>>py[i];
		g[i]=i;
		sx[i]=make_pair(px[i],i);
		sy[i]=make_pair(py[i],i);
	}	
	sort(sx,sx+n);
	sort(sy,sy+n);
	set<pair<int,pair<int,int> > >s;
	for(int i=0;i<n-1;i++){
		s.insert(make_pair(op(sx[i].second,sx[i+1].second),make_pair(sx[i].second,sx[i+1].second)));
		s.insert(make_pair(op(sy[i].second,sy[i+1].second),make_pair(sy[i].second,sy[i+1].second)));
	}
	long long res=0;
	while((int)s.size()){
		pair<int,pair<int,int> > p=*s.begin();
		s.erase(s.begin());
		int x=p.second.first,y=p.second.second;
		res+=(long long)value(x,y)*op(x,y);
	}
	cout<<res;
	return 0;
} 