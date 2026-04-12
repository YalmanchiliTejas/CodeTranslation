#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

typedef long long LL;
const LL inf=0x3f3f3f3f3f3f3f3fLL;
const int MX=200011;
struct It{
	int x[2];
	It(int _x0=0,int _x1=0){x[0]=_x0,x[1]=_x1;}
}s[MX];
inline bool operator<(const It &a,const It &b){return a.x[0]<b.x[0];}
int n;
LL solvesame(int mxit){
	int d=s[mxit].x[1]-s[1].x[0];
	LL ans=inf;
	int mx=max(s[mxit].x[0],s[1].x[1]),mn=min(s[mxit].x[0],s[1].x[1]);
	mx=max(mx,s[n].x[0]);
	for(int i=2;i<=n;i++)if(i!=mxit){
		ans=min(ans,(LL)d*(mx-min(mn,s[i].x[0])));
		mx=max(mx,s[i].x[1]),mn=min(mn,s[i].x[1]);
	}
	ans=min(ans,(LL)d*(mx-mn));
	return ans;
}
LL solvediff(int mxit){
	int mn=s[mxit].x[1],mx=s[1].x[0];
	if(mxit!=1){
		mn=s[1].x[1],mx=s[mxit].x[0];
	}
	for(int i=2;i<=n;i++)if(i!=mxit)mn=min(mn,s[i].x[1]),mx=max(mx,s[i].x[0]);
	return (LL)(s[mxit].x[1]-mn)*(mx-s[1].x[0]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&s[i].x[0],&s[i].x[1]);
		if(s[i].x[0]>s[i].x[1])swap(s[i].x[0],s[i].x[1]);
	}
	sort(s+1,s+n+1);
	int mxit=0,mxx=0;
	for(int i=1;i<=n;i++)if(s[i].x[1]>mxx)mxx=s[i].x[1],mxit=i;
	LL ans=inf;
	if(mxit>1)ans=min(ans,solvesame(mxit));
	ans=min(ans,solvediff(mxit));
	printf("%lld\n",ans);
	return 0;
}
