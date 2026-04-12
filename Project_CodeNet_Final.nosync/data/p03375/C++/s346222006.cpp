#include<cstdio>
using namespace std;
typedef long long ll;
int n,p,ans,C[3100][3100],S[3100][3100],p2[3100],p22[3100];
int qpow(int x,int a){
	int res=1;
	while (a){
		if (a&1) res=(ll)res*x%p;
		x=(ll)x*x%p; a>>=1;
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&p);
	C[0][0]=1; S[0][0]=1;
	for (int i=1;i<=n+1;i++){
		C[i][0]=1;
		for (int j=1;j<=i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
			S[i][j]=(S[i-1][j-1]+(ll)S[i-1][j]*j%p)%p;
		}
	}
	int tmp=1;
	p2[n]=1; p22[n]=2;
	for (int i=n-1;i>=0;i--){
		p2[i]=(p2[i+1]<<1)%p;
		tmp=(tmp<<1)%(p-1);
		p22[i]=qpow(2,tmp);
	}
	int op=-1;
	for (int i=0;i<=n;i++){
		op=-op;
		int mul=(C[n][i]*op+p)%p,mul2=1;
		int sum=0;
		for (int j=0;j<=i;j++){
			sum=(sum+(ll)S[i+1][j+1]*p22[i]%p*mul2%p)%p;
			mul2=(ll)mul2*p2[i]%p;
		}
		ans=(ans+(ll)mul*sum%p)%p; 
	}
	printf("%d\n",ans);
	return 0;
}
