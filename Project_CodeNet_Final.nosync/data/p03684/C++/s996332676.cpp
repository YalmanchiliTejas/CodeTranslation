#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <iostream>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> PP;

int n;
P p[100001];
vector<int> y[100001];
vector<int> xi;
vector<P> query;
vector<PP> edge;
int rankk[100001];
int par[100001];

void init(){
	for(int i=0;i<n;i++){
		par[i]=i;
		rankk[i]=0;
	}
}

int find(int x){
	if(par[x]==x){
		return x;
	}else{
		return par[x]=find(par[x]);
	}
}

void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return;
	if(rankk[x]<rankk[y]){
		par[x]=y;
	}else{
		par[y]=x;
		if(rankk[x]==rankk[y])rankk[x]++;
	}
}

bool same(int x,int y){
	return find(x)==find(y);
}

int main(void){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&p[i].first,&p[i].second);
		xi.push_back(p[i].first);
	}
	sort(xi.begin(),xi.end());
	xi.erase(unique(xi.begin(),xi.end()),xi.end());
	sort(p,p+n);
	for(int i=0;i<n;i++){
		p[i].first=lower_bound(xi.begin(),xi.end(),p[i].first)-xi.begin();
		query.push_back(P(p[i].second,p[i].first));
	}
	for(int i=0;i<(int)xi.size()-1;i++){
		edge.push_back(PP(xi[i+1]-xi[i],P(i,i+1)));
	}
	sort(query.begin(),query.end());
	for(int i=0;i<(int)query.size()-1;i++){
		int f=query[i+1].second;
		int t=query[i].second;
		int cost=query[i+1].first-query[i].first;
		edge.push_back(PP(cost,P(f,t)));
	}
	sort(edge.begin(),edge.end());
	init();
	ll res=0;
	for(int i=0;i<edge.size();i++){
		if(!same(edge[i].second.first,edge[i].second.second)){
			unite(edge[i].second.first,edge[i].second.second);
			res=(ll)res+edge[i].first;
		}
	}
	printf("%lld\n",res);
	return 0;
}
