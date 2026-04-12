#include<stdio.h>
typedef long long ll;
int p;
int mul(int a,int b){return(ll)a*b%p;}
int pow(int a,int b){
	int s=1;
	while(b){
		if(b&1)s=mul(s,a);
		a=mul(a,a);
		b>>=1;
	}
	return s;
}
int fac[3010],rfac[3010],st[3010][3010],pw[9000010],p2[3010];
void pre(int n){
	int i,j;
	fac[0]=1;
	for(i=1;i<=n;i++)fac[i]=mul(fac[i-1],i);
	rfac[n]=pow(fac[n],p-2);
	for(i=n;i>0;i--)rfac[i-1]=mul(rfac[i],i);
	p2[0]=1;
	for(i=1;i<=n;i++)p2[i]=p2[i-1]*2%(p-1);
	pw[0]=1;
	for(i=1;i<=n*n;i++)pw[i]=mul(pw[i-1],2);
	n++;
	st[0][0]=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++)st[i][j]=(mul(st[i-1][j],j)+st[i-1][j-1])%p;
	}
}
int C(int n,int k){return mul(fac[n],mul(rfac[k],rfac[n-k]));}
int main(){
	int n,i,j,s,t;
	scanf("%d%d",&n,&p);
	pre(n);
	s=0;
	for(i=0;i<=n;i++){
		t=0;
		for(j=0;j<=i;j++)(t+=mul(st[i+1][j+1],pw[(n-i)*j]))%=p;
		(s+=(i&1?-1:1)*mul(C(n,i),mul(t,pow(2,p2[n-i]))))%=p;
	}
	printf("%d",(s+p)%p);
}