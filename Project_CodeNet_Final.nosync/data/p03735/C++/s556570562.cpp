#include <cstdio>
#include <algorithm>
#define N 200007
#ifdef WIN32
#define L_L "%I64d"
#else
#define L_L "%lld"
#endif
#define IL inline
#define REP(a,b,c) for(a=b;a<=c;a++)
#define PER(a,b,c) for(a=b;a>=c;a--)
using namespace std;
typedef long long lol;
int n,rmi[N],rma[N];lol ans;
IL int rd(){
	int res=0;char c;while((c=getchar())<'0'||c>'9');
	while(c>='0'&&c<='9')res=res*10+c-'0',c=getchar();return res;
}
struct nd{
	int x,y;
	IL void init(){x=rd(),y=rd();if(x>y)swap(x,y);}
	IL bool operator < (const nd &b) const{return x<b.x||(x==b.x && y<b.y);}
}a[N];
int main(){
	n=rd();int i,mi=1e9,ma=1,s;
	REP(i,1,n)a[i].init(),ma=max(ma,a[i].y),mi=min(mi,a[i].y);
	sort(a+1,a+1+n);ans=1LL*(ma-mi)*(a[n].x-a[1].x);
	s=ma-a[1].x,mi=1e9,ma=1;rmi[n+1]=1e9,rma[n+1]=1;
	PER(i,n,1)rmi[i]=min(rmi[i+1],a[i].x),rma[i]=max(rma[i+1],a[i].x);
	REP(i,1,n){
		mi=min(mi,a[i].y),ma=max(ma,a[i].y);
		ans=min(ans,1LL*s*(max(ma,rma[i+1])-min(mi,rmi[i+1])));
	}
	printf(L_L,ans);
  return 0;
}