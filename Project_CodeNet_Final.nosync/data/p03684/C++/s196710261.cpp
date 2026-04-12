#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
using namespace std;
const int N = 100005;
struct P{
	int x,y,num;
}p[2*N];
bool cmp(P x,P y){
	return x.x < y.x;
}
bool cmp1(P x,P y){
	return x.y < y.y;
}
struct E{
	int from,to,v;
}e[2*N];
int node,f[N],n;
void addedge(int from,int to,int v){
	node++;	e[node].from = from;	e[node].to = to;	e[node].v = v;
}
bool cmp2(E x,E y){
	return x.v < y.v;
}
int ff(int x){
	if (f[x] == x)	return f[x];
	return f[x] = ff(f[x]);
}
typedef long long ll;
int main(){
//	freopen("read.in","r",stdin);
	cin >> n;
	for (int i = 1;i <= n;i++)	f[i] = i;
	for (int i = 1;i <= n;i++){
		cin >> p[i].x >> p[i].y;
		p[i].num = i;
	}
	sort(p+1,p+n+1,cmp);
	for (int i = 1;i < n;i++){
		addedge(p[i].num,p[i+1].num,p[i+1].x-p[i].x);
	}
	sort(p+1,p+n+1,cmp1);
	for (int i = 1;i < n;i++){
		addedge(p[i].num,p[i+1].num,p[i+1].y-p[i].y);
	}
	sort(e+1,e+node+1,cmp2);
	ll ans = 0;	int sum = 1;
	for (int i = 1;i <= node;i++){
		int x = e[i].from,y = e[i].to;
		x = ff(x);	y = ff(y);
		if (x == y)	continue;
		f[x] = y;	ans += e[i].v;	sum++;
		if (sum == n)	break;
	}
	cout << ans << endl;
	return 0;
}