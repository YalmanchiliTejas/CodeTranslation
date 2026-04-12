#include<bits/stdc++.h>
#define pi 3.1415926535898
#define eps 1e-9 
using namespace std;
long long read(){
    long long xx=0,flagg=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')
        ch=getchar();
    if(ch=='-'){
        flagg=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        xx=xx*10+ch-'0';
        ch=getchar();
    }
    return xx*flagg;
}
void pus(long long xx,long long flagg){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10)
        pus(xx/10,0);
    putchar(xx%10+'0');
    if(flagg==1)
        putchar(' ');
    if(flagg==2)
        putchar('\n');
    return;
}
long long ksm(long long u,long long v,long long mod){
	long long o=1;
	while(v){
		if(v&1)
			o=o*u%mod;
		u=u*u%mod;
		v>>=1;
	}
	return o;
}
long long n,i,j,k,C[3005][3005],f[3005][3005],p1,sum,x,ans;
int main(){
	n=read();
	const int mo=read();
	for(i=0;i<=n;i++){
		C[i][0]=1;
		f[i][0]=1;
		for(j=1;j<=i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
			f[i][j]=(f[i-1][j-1]+f[i-1][j]*(j+1))%mo;
		}
	}
	for(i=0;i<=n;i++){
		if(i&1)
			k=mo-C[n][i];
		else
			k=C[n][i];
		p1=ksm(2,n-i,mo);
		sum=0;x=1;
		for(j=0;j<=i;j++){
			sum=(sum+f[i][j]*x)%mo;
			x=x*p1%mo;
		}
		ans=(ans+k*sum%mo*ksm(2,ksm(2,n-i,mo-1),mo))%mo;
	}
	pus(ans,2);
    return 0;
}