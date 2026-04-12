#include<bits/stdc++.h>
#define lowbit(i) ((i)&(-i))
#define lson(i) ((i)<<1)
#define rson(i) ((i)<<1|1)
#define ft first
#define se second
#define MAXN 100007
using namespace std;

typedef long long ll;typedef unsigned long long ul;
typedef pair<int,int> pii;typedef pair<ll,ll> pll;
typedef vector<string> vss;
typedef vector<int> vii;typedef vector<pii> vpi;
typedef queue<int> qii;typedef queue<pii> qpi;

const int inf=2e9+7;

struct edge{
	ll x,y,val;
	edge(int _x,int _y,int _val){x=_x,y=_y,val=_val;}
};

vector<edge> v;

struct node{
	int x,y,num;
}dot1[MAXN],dot2[MAXN];

bool cmp1(node x,node y){
	return x.x<y.x;
}

bool cmp2(node x,node y){
	return x.y<y.y;
}

bool comp(edge x,edge y){
	return x.val<y.val;
}

int n,fa[MAXN];
ll res;

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy)
		fa[fx]=y;
}

int main()
{
// 	freopen("","r",stdin);
// 	freopen("","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&dot1[i].x,&dot1[i].y);
		dot2[i].x=dot1[i].x;dot2[i].y=dot1[i].y;
		dot2[i].num=dot1[i].num=i;
	}
	
	//建边(删除无用边) 
	sort(dot1+1,dot1+n+1,cmp1);
	sort(dot2+1,dot2+n+1,cmp2);
//	for(int i=1;i<=n;i++){
//		printf("num %d:(%d,%d)\n",i,dot1[i].x,dot1[i].y);
//	}
	for(int i=2;i<=n;i++){
		v.push_back( edge(dot1[i-1].num,dot1[i].num,dot1[i].x-dot1[i-1].x) );
		v.push_back( edge(dot2[i-1].num,dot2[i].num,dot2[i].y-dot2[i-1].y) );
	}
	sort(v.begin(),v.end(),comp);
	
	//初始化 
	for(int i=1;i<=n;i++)
		fa[i]=i;

//	for(int i=0;i<v.size();i++){
//		printf("(%d,%d) dis=%d\n",v[i].x,v[i].y,v[i].val);
//	}
	//Kruscal
	for(int i=0;i<v.size();i++){
		if(find(v[i].x)!=find(v[i].y)){
			merge(v[i].x,v[i].y);
			res+=v[i].val;
		}
	}
	printf("%lld\n",res);
	return 0;
}
