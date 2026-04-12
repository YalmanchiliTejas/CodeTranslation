#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>

using namespace std;

const int N=3005;
//const int P=998244353;

int n;
long long P;

#define multi(x,y) ((((x)%P)*((y)%P))%P)

inline long long ksm(long long base,long long x){
	long long res=1;
	while(x){
		if(x&1) res=multi(res,base);
		base=multi(base,base);
		x>>=1;
	}
	return res;
}

long long f[N][N];
long long ff[N][N];
long long g[N];
long long ans;
long long fac[N],inv_fac[N];
long long exp_2[N],exp_exp_2[N],exp_exp_exp_2[N];

inline void init_f(){
	f[0][0]=1;
	f[1][0]=1;
	f[1][1]=1;
	for(int i=2;i<=n;i++){
		f[i][0]=1;
		for(int j=1;j<=i;j++){
			f[i][j]=(P+f[i-1][j-1]+multi((j+1),f[i-1][j]))%P;
		}
	}
}


/*
inline void init_f(){
	//f[0][0]=1;
	//f[1][0]=1;
	ff[1][1]=1;
	for(int i=2;i<=n;i++){
		//f[i][0]=1;
		for(int j=1;j<=i;j++){
			ff[i][j]=(ff[i-1][j-1]+(((j)*ff[i-1][j])%P))%P;
		}
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		//f[i][j]=ff[i][j];
		for(int j=0;j<=i;j++){
			f[i][j]=(ff[i][j]+(ff[i][j+1]*(j+1))%P)%P;
		}
	}
}
*/


inline long long C(int x,int y){
    if(y<0||y>x)return 0;
	return multi(fac[x],multi(inv_fac[y],inv_fac[x-y]));
}

void init(){
	scanf("%d%lld",&n,&P);
	init_f();
	fac[0]=1;
	inv_fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=multi(fac[i-1],i),inv_fac[i]=ksm(fac[i],P-2);
	exp_2[0]=1;
	exp_exp_2[0]=2;
	exp_exp_exp_2[0]=1;
	for(int i=1;i<=n;i++) exp_2[i]=(exp_2[i-1]*2)%(P-1),exp_exp_2[i]=ksm(2,exp_2[i]),exp_exp_exp_2[i]=ksm(2,i);
	
	//printf("...\n");
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			//g[i]+=multi(ksm(2,ksm(2,n-i)),multi(f[i][j],ksm(2,(j*(n-i))%P)));
			g[i]+=multi(exp_exp_2[n-i],multi(f[i][j],ksm(exp_exp_exp_2[n-i],j)));
			g[i]%=P;
			/*
			if(g[i]>P) cout<<"Error"<<endl;
			cout<<i<<' '<<j<<' '<<g[i]<<endl;
			assert(g[i]<=P);
			*/
		}
	}
	
	/*
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			printf("%d ",f[i][j]);
		}
		printf("\n");
	}
	*/
	
	for(int i=0;i<=n;i++){
		if(i%2==0) ans+=multi(C(n,i),g[i]),ans%=P;
		else ans-=multi(C(n,i),g[i]),ans%=P,ans+=P,ans%=P;
	}
	printf("%lld\n",ans%P);
}

int main(){
	init();
	return 0;
}