#include<bits/stdc++.h>
#define mo 998244353
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
long long len,n,m,f[10005][5005],i,j,jc[10005],ny[10005],ans;
long long ksm(long long u,long long v){
	long long o=1;
	while(v){
		if(v&1)
			o=o*u%mo;
		u=u*u%mo;
		v>>=1;
	}
	return o;
}
long long C(long long u,long long v){
	return jc[u]*ny[v]%mo*ny[u-v]%mo;
}
char s[10005],c[10005];
int main(){
	scanf("%s%s",s+1,c+1);
	len=strlen(s+1);
	for(i=1;i<=len;i++)
		if(s[i]=='1'&&c[i]=='1')
			n++;
		else if(s[i]=='1'&&c[i]=='0')
			m++;
	jc[0]=1;
	for(i=1;i<=n+m;i++)
		jc[i]=jc[i-1]*i%mo;
	ny[n+m]=ksm(jc[n+m],mo-2);
	for(i=n+m-1;i>=0;i--)
		ny[i]=ny[i+1]*(i+1)%mo;
	f[0][0]=1;
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++){
			if(j!=0)
				f[i][j]=(f[i][j]+f[i][j-1]*j*j)%mo;
			if(i!=0)
				f[i][j]=(f[i][j]+f[i-1][j]*i*j)%mo;
		}
	for(i=0;i<=n;i++)
		ans=(ans+C(n,i)*jc[i]%mo*jc[i]%mo*C(n+m,i)%mo*f[n-i][m])%mo;
	pus(ans,2);
	return 0;
}