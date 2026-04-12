#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
int n,id[maxn],sz,cnt,ans;
struct node {
	int x,y,bh;
} d[maxn];
struct edge {
	int from,to,dis;
} m[maxn*2];
int find(int a) {
	if (id[a]==a)
		return a;
	id[a]=find(id[a]);
	return id[a];
}
void connect(int a,int b) {
	id[find(a)]=find(b);
}
bool cmp1(node a,node b) {
	return a.x<b.x;
}
bool cmp2(node a,node b) {
	return a.y<b.y;
}
bool cmp3(edge a,edge b) {
	return a.dis<b.dis;
}
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		d[i].bh=i;
		scanf("%d %d",&d[i].x,&d[i].y);
	}
	sz=0;
	sort(d+1,d+(n+1),cmp1);
	for (int i=2;i<=n;i++) {
		sz++;
		m[sz].from=d[i-1].bh;
		m[sz].to=d[i].bh;
		m[sz].dis=d[i].x-d[i-1].x;
	}
	sort(d+1,d+(n+1),cmp2);
	for (int i=2;i<=n;i++) {
		sz++;
		m[sz].from=d[i-1].bh;
		m[sz].to=d[i].bh;
		m[sz].dis=d[i].y-d[i-1].y;
	}
	sort(m+1,m+(sz+1),cmp3);
	ans=0; cnt=n;
	for (int i=1;i<=n;i++)
		id[i]=i;
	for (int i=1;i<=sz;i++) {
		if (cnt==1)
			break;
		int a=m[i].from,b=m[i].to;
		if (find(a)!=find(b)) {
			cnt--;
			connect(a,b);
			ans+=m[i].dis;
		}
	}
	printf("%d\n",ans);
	return 0;
}