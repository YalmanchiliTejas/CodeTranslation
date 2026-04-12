#include<cstdio>
#include<algorithm>
#include<cmath>
#define MAXN 100009
using namespace std;

int n;
struct data{
	int x,y,id;
}a[MAXN];
struct E{
	int from,to,val,next;
}edge[MAXN<<1];
int head[MAXN],edge_num;
int ans;
int fa[MAXN];

bool cmp1(const data &q,const data &w){
	return q.x<w.x;
}
bool cmp2(const data &q,const data &w){
	return q.y<w.y;
}
bool cmp3(const E &q,const E &w){
	return q.val<w.val;
}

int Find(int x){
	if(fa[x]!=x) fa[x]=Find(fa[x]);
	return fa[x];
}

void addedge(int x,int y,int v){
	edge[++edge_num].next=head[x];
	edge[edge_num].to=y;
	edge[edge_num].from=x;
	edge[edge_num].val=v;
	head[x]=edge_num;
}

void Kruskal(){
	sort(edge+1,edge+edge_num+1,cmp3);
	int i;int cnt=0;
	for(i=1;i<=n;i++)
		fa[i]=i;
	for(i=1;i<=edge_num;i++){
		int ff=Find(edge[i].from),tt=Find(edge[i].to);
		if(ff!=tt){
			fa[ff]=tt;
			ans+=edge[i].val;
			cnt++;
			if(cnt==n-1)
				return;
		}
	}
}

void solve(){
	int i;
	sort(a+1,a+n+1,cmp1);
	for(i=2;i<=n;i++)
		addedge(a[i-1].id,a[i].id,a[i].x-a[i-1].x);
	sort(a+1,a+n+1,cmp2);
	for(i=2;i<=n;i++)
		addedge(a[i-1].id,a[i].id,a[i].y-a[i-1].y);
	Kruskal();
	printf("%d\n",ans);
}

int main(){
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y),a[i].id=i;
	solve();
	return 0;
}
