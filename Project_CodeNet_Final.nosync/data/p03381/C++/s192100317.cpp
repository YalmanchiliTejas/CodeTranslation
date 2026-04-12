#include <bits/stdc++.h>
#define pb push_back
#define cmin(a,b) (a>b?a=b:a)
#define cmax(a,b) (a<b?a=b:a)
#define mem(a,k) memset(a,k,sizeof(a))
#define lop(i,s,t) for(int i=s;i<(t);++i)
#define rep(i,s,t) for(int i=s;i<=(t);++i)
#define dec(i,s,t) for(int i=s;i>=(t);--i)
#define fore(i,v) for(int i=g[v],d=es[i].d;i;i=es[i].nxt,d=es[i].d)
using namespace std;
 
#define Pr(f,...) //printf(f,##__VA_ARGS__),fflush(stdout)
 
typedef long long ll;
 
const int N=3e5+50,P=1e9+7;

void upd(int &a,int b) { a+=b; if(a>=P)a-=P; }
 
int n,a[N],b[N];
int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
	//freopen("dat.in","r",stdin);
	//freopen("my.out","w",stdout);
#endif
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",a+i);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	int x=b[n/2],y=b[n/2+1];
	rep(i,1,n)printf("%d\n",a[i]<=x?y:x);
	return 0 ;
}