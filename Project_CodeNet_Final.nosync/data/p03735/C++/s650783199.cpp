#include<bits/stdc++.h>
using namespace std;

template <typename T>
inline T read(){
	T x=0,f=1;char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-f;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c-48);c=getchar();}
	return x*f;
}

#define lint long long int
#define ulint unsigned lint
#define readint read<int>()
#define readlint read<lint>()
const int inf=1e9+1e7,MAXN=2e5+1e1;
const lint INF=1e18+1e9;

struct Node{
	lint r,b;
}a[MAXN];

lint Ans=INF,maxn,minn=inf;
bool vis[MAXN],vmax,vmin;
int n;

bool Cmpr(Node A,Node B){
	return (A.r==B.r ? A.b<B.b : A.r<B.r);
}

bool Cmpb(Node A,Node B){
	return (A.b==B.b ? A.r<B.r : A.b<B.b);
}

void Solve1(){
	lint maxm=maxn,minm=minn;
	for(int i=1;i<=n;i++) maxm=min(a[i].b,maxm),minm=max(a[i].r,minm);
	// printf("minn = %lld, maxn = %lld, maxm = %lld, minm = %lld\n",minn,maxn,maxm,minm);
	Ans=min((minm-minn)*(maxn-maxm),Ans);
	return;
}

void Solve2(){
	lint maxm=max(a[n].r,a[1].b),minm=min(a[n].r,a[1].b),tmp=INF;
	for(int i=2;i<n;i++) if(a[i].b<minm) minm=a[i].b,vis[i]=true;
	for(int i=2;i<n;i++) if(a[i].r>maxm) maxm=a[i].r,vis[i]=true;
	for(int i=2;i<n;i++) if(minm<=a[i].b && a[i].b<=maxm) vis[i]=true;
	for(int i=2;i<n;i++) if(minm<=a[i].r && a[i].r<=maxm) vis[i]=true;
	// printf("maxm = %lld, minm = %lld\n",maxm,minm);
	for(int i=2;i<n;i++) if(!vis[i]){
		tmp=min(maxm-min(a[i].r,minm),tmp);
		maxm=max(a[i].b,maxm);
		// printf("j = %d, tmp = %lld, maxm = %lld, minm = %lld\n",i,tmp,maxm,minm);
	}
	if(tmp<INF) Ans=min((maxn-minn)*tmp,Ans);
	else Ans=min((maxn-minn)*(maxm-minm),Ans);
	return;
}

int main(void){

	// freopen("testdata.in","r",stdin);
	// freopen("testdata.out","w",stdout);

	scanf("%d",&n);
	for(int i=1;i<=n;i++) a[i].r=readint,a[i].b=readint;
	for(int i=1;i<=n;i++) if(a[i].r>a[i].b) swap(a[i].r,a[i].b);
	sort(a+1,a+n+1,Cmpb),maxn=a[n].b,vmax=(a[n].b==a[n-1].b);
	sort(a+1,a+n+1,Cmpr),minn=a[1].r,vmin=(a[1].r==a[2].r);
	sort(a+1,a+n+1,Cmpb),sort(a+1,a+n,Cmpr);
	if(!vmax && !vmin && minn==a[n].r && maxn==a[n].b){
		// printf("Oh\n");
		Solve1(),Solve2();
	}
	else minn=a[1].r,maxn=a[n].b,Solve1(),Solve2();
	// for(int i=1;i<=n;i++) printf("i = %d, r = %lld, b = %lld\n",i,a[i].r,a[i].b);
	printf("%lld\n",Ans);

	return 0;
}