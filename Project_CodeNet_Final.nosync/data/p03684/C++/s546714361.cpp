#include <bits/stdc++.h>
using namespace std;
long long ans;
int n,fa[100003],r[100003];
pair<int,int> a[100003],x[100003],y[100003];
priority_queue <pair<int,pair<int,int> > > q;
int find_fa(int x){
	if(fa[x]==x) return x;
	return fa[x]=find_fa(fa[x]);
}
void uni(int x,int y){
	x=find_fa(x);
	y=find_fa(y);
	if (r[x]<r[y]) fa[x]=y;
	else{
		fa[y]=x;
		if(r[x]==r[y]) r[x]++;
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++) fa[i]=i;
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
		x[i]={a[i].first,i};
		y[i]={a[i].second,i};
	}
	sort(x,x+n);
	sort(y,y+n);
	for(int i=0;i<n-1;i++){
		q.push({-(x[i+1].first-x[i].first),{x[i].second,x[i+1].second}});
		q.push({-(y[i+1].first-y[i].first),{y[i].second,y[i+1].second}});
	}
	while(q.size()){
		int c=-q.top().first,p1=q.top().second.first,p2=q.top().second.second;
		if(find_fa(p1)!=find_fa(p2)){
			uni(p1,p2);
			ans+=c;
		}
		q.pop();
	}
	cout<<ans;
	return 0;
}