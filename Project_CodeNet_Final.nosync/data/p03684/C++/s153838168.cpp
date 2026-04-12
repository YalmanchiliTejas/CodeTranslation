#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int > vi;
typedef pair<int ,int > pii;
typedef vector<pii> vii;
const int inf=0x3f3f3f3f, maxn=100007, mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3fLL;
const ll P=19260817;
int fa[100007];
int n;
inline int find(int x){
	return x==fa[x]? x: fa[x]=find(fa[x]);
}
struct node{
	int x,y,id;
}a[100007];
inline bool cmp1(const node& a,const node& b){
	return a.x<b.x;
}
inline bool cmp2(const node& a,const node& b){
	return a.y<b.y;
}
struct edge{
	int x,y,val;
}e[100005<<2];
inline bool cmp3(const edge& a,const edge &b){
	return a.val<b.val;
}
int cnt;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y),a[i].id=i;
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<n;i++){
		e[++cnt].x=a[i].id;
		e[cnt].y=a[i+1].id;
		e[cnt].val=abs(a[i].x-a[i+1].x);
	}
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<n;i++){
		e[++cnt].x=a[i].id;
		e[cnt].y=a[i+1].id;
		e[cnt].val=abs(a[i].y-a[i+1].y);
	}
	sort(e+1,e+cnt+1,cmp3);
	int p=0;
	ll ans=0;
	for(int i=1;i<=cnt;i++){
		int fx=find(e[i].x);
		int fy=find(e[i].y);
		if(fx==fy)continue;
		fa[fx]=fy;
		ans+=e[i].val;
		p++;
		if(p==n-1)break;
	}
	printf("%lld",ans);
    return 0;
}
