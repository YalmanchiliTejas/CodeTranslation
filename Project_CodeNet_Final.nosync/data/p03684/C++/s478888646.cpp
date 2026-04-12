#include <bits/stdc++.h>

#define lld long long
#define pp pair<int,int>
#define pb push_back
#define MOD 1000000007
#define left lleft
#define right rright
#define INF 2000000000
#define Linf 1000000000000000000LL
#define next nnext
#define minus mminus

using namespace std;

int N; lld ans;
int par[100002];
struct data{
	int num;
	lld x,y;
}a[100002];
vector<pair<int,pair<int,int>>> edge;

int getpar(int x){
	return (x == par[x])?x:par[x]=getpar(par[x]);
}

int main(){
	scanf("%d",&N);
	for(int i=1; i<=N; i++){
		scanf("%lld %lld",&a[i].x,&a[i].y);
		a[i].num= i;
		par[i] = i;
	}
	sort(a+1,a+N+1,[&](data &x,data &y){
		return x.x < y.x;
	});
	for(int i=1; i<N; i++){
		edge.pb({a[i+1].x-a[i].x,{a[i].num,a[i+1].num}});
	}
	for(int i=2; i<=N; i++){
		edge.pb({a[i].x-a[i-1].x,{a[i].num,a[i-1].num}});
	}
	sort(a+1,a+N+1,[&](data &x,data &y){
		return x.y < y.y;
	});
	for(int i=1; i<N; i++){
		edge.pb({a[i+1].y-a[i].y,{a[i].num,a[i+1].num}});
	}
	for(int i=2; i<=N; i++){
		edge.pb({a[i].y-a[i-1].y,{a[i].num,a[i-1].num}});
	}
	sort(edge.begin(),edge.end());
	for(auto &i : edge){
		int value;
		int x,y;
		value = i.first;
		x = i.second.first; y = i.second.second;
		x = getpar(x); y = getpar(y);
		if(x == y) continue;
		ans += value;
		par[x] = y;
	}
	printf("%lld\n",ans);

	return 0;
}
