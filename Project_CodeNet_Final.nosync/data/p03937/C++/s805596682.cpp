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

#define Pr(f,...) //fprintf(stderr,f,##__VA_ARGS__),fflush(stderr)

typedef long long ll;

template<typename T>
void read(T &x){
	x=0; 
	char c;
	for(c=getchar();!isdigit(c);c=getchar()); 
	for(;isdigit(c);c=getchar())x=x*10+c-'0'; 
}

const int N=10,P=1e9+7;

int mul(int a,int b){ return 1ll*a*b%P; }
int add(int a,int b){ a+=b; return a>=P?a-P:a; }
int sub(int a,int b){ a-=b; return a<0?a+P:a; }

int n,m,x,y,L[N],R[N];
char a[N][N]; 

int main(int argc,char *argv[]){
#ifdef GCURIOUSCAT
	freopen("dat.in","r",stdin);
	freopen("my.out","w",stdout);
#endif
	read(n),read(m); 
	bool suc=true;
	rep(i,1,n){
		scanf("%s",a[i]+1); 
		L[i]=m+1,R[i]=0; 
		rep(j,1,m)if(a[i][j]=='#'){
			cmin(L[i],j); 
			cmax(R[i],j); 
		}
		if(i>1)suc&=L[i]>=R[i-1]; 
	}
	suc&=L[1]==1&&R[n]==m;
	puts(suc?"Possible":"Impossible"); 
	return 0;
}
