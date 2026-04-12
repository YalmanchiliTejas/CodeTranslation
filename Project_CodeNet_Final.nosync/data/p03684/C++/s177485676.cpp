#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<deque>
#include<stack>
#include<cmath>
#include<ctime>
#include<complex>
#include<list>
using namespace std;

const int N=100005;
int n,side;
int fa[N];
long long ans;
pair<int,int> X[N],Y[N];
priority_queue<pair<int,pair<int,int> > > pq;

inline int Find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=Find(fa[x]);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		X[i]=make_pair(x,i);
		Y[i]=make_pair(y,i);
	}
	for(int i=0;i<n;i++) fa[i]=i;
	sort(X,X+n);
	sort(Y,Y+n);
	for(int i=0;i<n-1;i++) pq.push(make_pair(X[i].first-X[i+1].first,make_pair(X[i].second,X[i+1].second)));
	for(int i=0;i<n-1;i++) pq.push(make_pair(Y[i].first-Y[i+1].first,make_pair(Y[i].second,Y[i+1].second)));
	while(side<n-1){
		pair<int,pair<int,int> > p=pq.top();
		pq.pop();
		int x=p.second.first;
		int y=p.second.second;
		int dis=-p.first;
		x=Find(x);
		y=Find(y);
		if(x!=y){
			fa[x]=y;
			side++;
			ans+=dis;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}