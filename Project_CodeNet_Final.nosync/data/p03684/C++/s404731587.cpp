#include <bits/stdc++.h>
#define mset(a,b) memset(a,b,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof b)
#define max(a,b) ((a)<(b)?(b):(a))
#define swap(a,b) a^=b^=a^=b 
#define lb(x) ((x)&(-(x)))
#define dalao 1000000007
#define inf 0x3f3f3f3f
#define N 200010
using namespace std;
typedef long long ll;
struct point{
	int x,y,no;
}a[N];
struct e{
	int a,b,v;
	bool operator <(const e& c)const{return v<c.v;}
}b[2000010];
int n,cnt,fa[N];
ll ans,ans2;
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline bool cmp1(const point a,const point b){return a.x<b.x;}
inline bool cmp2(const point a,const point b){return a.y<b.y;}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y),a[i].no=fa[i]=i;
	sort(a+1,a+1+n,cmp1);
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=min(i+10,n);j++)b[++cnt]=(e){a[i].no,a[j].no,min(abs(a[i].x-a[j].x),abs(a[i].y-a[j].y))};
	}
	sort(a+1,a+1+n,cmp2);
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=min(i+10,n);j++)b[++cnt]=(e){a[i].no,a[j].no,min(abs(a[i].x-a[j].x),abs(a[i].y-a[j].y))};
	}
	sort(b+1,b+1+cnt);
	for(int i=1;i<=cnt;i++){
		int x=find(b[i].a),y=find(b[i].b);
		if(x^y)fa[x]=y,ans+=b[i].v;
	}
	cout<<ans;
	return 0;
}