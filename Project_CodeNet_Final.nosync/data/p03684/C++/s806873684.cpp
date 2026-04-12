//writer：Sakura
//problem：Built? 
//id：arc_076b 
//from：AtCoder

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <bits/stdc++.h>
#define N 100005
using namespace std;

typedef long long ll;

ll n,fa[N],a,ans=0;
priority_queue<pair<ll,pair<ll,ll> > > que;
pair<ll,ll> x[N],y[N];

int root(int x){//并查集 
	if(fa[x]==x)return x;
	else return fa[x]=root(fa[x]);
}

void link(int x,int y){//并查集归类 
	x=root(x);y=root(y);
	if(x==y)return;
	fa[x]=y;
}

int main(){
	//freopen("Built.in","r",stdin);
	//freopen("Built.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)fa[i]=i;//初始fa 
	for(int i=0;i<n;i++){
		scanf("%lld %lld",&x[i].first,&y[i].first);
		x[i].second=i;
		y[i].second=i;
		//second记录下标 
	}
	sort(x,x+n);sort(y,y+n);//按照横纵排序 
	
	/*for(int i=0;i<n;i++){
		printf("%lld %lld\n",x[i].first,y[i].first);
	}cout<<endl;
	for(int i=0;i<n;i++){
		printf("%lld %lld\n",x[i].second,y[i].second); 
	}cout<<endl; 
	*/
	
	for(int i=0;i<n-1;i++){//存入花费【min(abs(a-c),abs(b-d));】 
		que.push(make_pair(-(abs(x[i].first-x[i+1].first)),make_pair(x[i].second,x[i+1].second)));
		que.push(make_pair(-(abs(y[i].first-y[i+1].first)),make_pair(y[i].second,y[i+1].second)));
	}
	while(!que.empty()){
		pair<ll,ll> edge;
		ll xx,yy;//xx,yy分别为横纵 
		ll cost;//cost花费的yen 
		pair<ll, pair<ll,ll> > new_q;
		new_q=que.top();
		edge=new_q.second;
		cost=-new_q.first;
		xx=edge.first;yy=edge.second;//xx，yy分别是新的横纵 
		que.pop();
		if(root(xx)==root(yy))continue;
		link(xx,yy);//链接xxyy构成边 
		ans+=cost;
	}
	printf("%lld\n",ans);
	return 0;
}
