#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=1000005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
inline void read(int &x){
	x=0;char ch=getchar(),rev=0;
	while(ch>'9'||ch<'0') rev=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x=rev?-x:x;
}
inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,fa[N],ans;
struct node{int x,num;}a[N],b[N];
struct edge{int x,y,val;}p[N];
bool cmp(node a,node b){return a.x<b.x;}
bool cmp2(edge a,edge b){return a.val<b.val;}
inline int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;scanf("%d%d",&x,&y);
		a[i]=(node){x,i};b[i]=(node){y,i};
		fa[i]=i;
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<n;i++)
		p[i]=(edge){a[i].num,a[i+1].num,a[i+1].x-a[i].x},p[i+n-1]=(edge){b[i].num,b[i+1].num,b[i+1].x-b[i].x};
	sort(p+1,p+n*2-1,cmp2);
	for(int i=1;i<=n*2-2;i++){
		int x=find(p[i].x),y=find(p[i].y);
		if(x!=y){
			fa[x]=y;
			ans+=p[i].val;
		}
	}
	printf("%d\n",ans);
	return 0;
}