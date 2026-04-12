#include <bits/stdc++.h>
#define pb push_back
#define cmin(a,b) (a>b?a=b:a)
#define cmax(a,b) (a<b?a=b:a)
#define lop(i,s,t) for(int i=s;i<(t);++i)
#define rep(i,s,t) for(int i=s;i<=(t);++i)
#define dec(i,s,t) for(int i=s;i>=(t);--i)
#define fore(i,v) for(int i=g[v],d=es[i].d;i;i=es[i].nxt,d=es[i].d)
using namespace std;

typedef long long ll;

const int N=3005;
int n,P,phi_p,F[N][N],C[N][N],ans;

int mul(int a,int b){ return 1ll*a*b%P; }
int add(int a,int b){ a+=b; return a>=P?a-P:a; }
int sub(int a,int b){ a-=b; return a<0?a+P:a; }

int phi(int x){
	int res=1;
	for(int i=2;i*i<=x;++i){
		if(i%x==0){
			x/=i,res*=(i-1);
			while(x%i==0)x/=i,res*=i;
		}
	}
	if(x>1)res*=x-1;
	return res;
}

int pwr(int a,int k,int p=P){
	int res=1;
	for(;k;k>>=1,a=1ll*a*a%p){
		if(k&1)res=1ll*res*a%p;
	}
	return res;
}

int ways(int i){
	int res=0,arbi=pwr(2,pwr(2,n-i,phi_p)),x=pwr(2,n-i),w=1;
	rep(j,0,i){
		res=add(res,mul(F[i][j],mul(w,arbi)));
		w=mul(w,x);
	}
	return res;
}

int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
	freopen("dat.in","r",stdin);
	//freopen("my.out","w",stdout);
#endif
	cin>>n>>P; 
	phi_p=phi(P); 
	C[0][0]=1;
	rep(i,1,n){
		C[i][0]=1;
		rep(j,1,i)C[i][j]=add(C[i-1][j-1],C[i-1][j]);
	}
	F[0][0]=1;
	rep(i,1,n){
		F[i][0]=1;
		rep(j,1,i){
			F[i][j]=add(mul(F[i-1][j],j+1),F[i-1][j-1]);
		}
	}
	rep(i,0,n){
		int w=mul(C[n][i],ways(i)); 
		if(i%2==0)ans=add(ans,w);
		else ans=sub(ans,w); 
	}
	printf("%d\n",ans); 
	return 0;
}