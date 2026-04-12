#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char a[100010],b[100010];
int n,num,tot;
const int mod=998244353;
int jc[100010],inv[100010],ans;
const int G=3;
int x1[100010],x2[100010];
int fast_pow(int a,int x)
{
	int ans=1;
	for (;x;x>>=1,a=1ll*a*a%mod)
		if (x&1) ans=1ll*ans*a%mod;
	return ans;
}
void change(int y[],int len)
{
	int i,j,k;
	for (i=1,j=len/2;i<len-1;i++)
	{
		if (i<j) swap(y[i],y[j]);
		k=len/2;
		while (j>=k) j-=k,k>>=1;
		if (j<k) j+=k; 
	}
	return;
}
void fft(int y[],int len,int ifi)
{
	change(y,len);
	for (int h=2;h<=len;h<<=1)
	{
		int wn=fast_pow(G,(ifi==1)?(mod-1)/h:mod-1-(mod-1)/h);
		for (int j=0;j<len;j+=h)
		{
			int w=1;
			for (int k=j;k<j+h/2;k++)
			{
				int u=y[k];
				int t=1ll*w*y[k+h/2]%mod;
				y[k]=(u+t)%mod;
				y[k+h/2]=(1ll*u-t+mod)%mod;
				w=1ll*w*wn%mod;
			} 
		} 
	}
	if (ifi==-1)
	{
		int iv=fast_pow(len,mod-2);
		for (int i=0;i<len;i++) y[i]=1ll*y[i]*iv%mod;
	}
}
void add(int len)
{
	fft(x2,len,1);
	for (int i=0;i<len;i++) x2[i]=1ll*x2[i]*x2[i]%mod;
	fft(x2,len,-1);
	for (int i=num+1;i<len;i++) x2[i]=0;
}
int main()
{
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	for (int i=1;i<=n;i++)
	{
		if (a[i]=='1'&&b[i]=='1') num++;
		if (a[i]=='1') tot++;
	}
	jc[0]=1;
	for (int i=1;i<=tot+1;i++) jc[i]=1ll*jc[i-1]*i%mod;
	inv[tot+1]=fast_pow(jc[tot+1],mod-2);
	for (int i=tot;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod; 
	for (int i=0;i<=tot;i++) inv[i]=inv[i+1];

	int len=1;
	while (len<=2*num) len<<=1;
	x1[0]=1;
	for (int i=1;i<len;i++) x1[i]=0;
	for (int i=0;i<=num;i++) x2[i]=inv[i];
	for (int i=num+1;i<len;i++) x2[i]=0;
	
	for (int i=tot-num;i;i>>=1,add(len))
		if (i&1)
		{
			fft(x2,len,1);fft(x1,len,1);
			for (int j=0;j<len;j++) x1[j]=1ll*x1[j]*x2[j]%mod;
			fft(x1,len,-1);fft(x2,len,-1);
			for (int j=num+1;j<len;j++) x1[j]=0;
		}
	//cout<<len<<endl;
	
//	for (int i=1;i<=tot-num;i++)
//	{
//		for (int j=num+1;j<len;j++) x1[j]=0;
//		for (int j=0;j<len;j++) printf("%d ",x1[j]);cout<<endl;
//		for (int j=0;j<len;j++) printf("%d ",x2[j]);cout<<endl;
//		fft(x1,len,1);fft(x2,len,1);
//		for (int j=0;j<len;j++) printf("%d ",x1[j]);cout<<endl;
//		for (int j=0;j<len;j++) printf("%d ",x2[j]);cout<<endl;
//		for (int j=0;j<len;j++)
//			x1[j]=1ll*x1[j]*x2[j]%mod;
//		//for (int i=0;i<len;i++) printf("%d ",x1[i]);cout<<endl;
//		//for (int i=0;i<=tot;i++) printf("%d ",x2[i]);cout<<endl;
//		fft(x1,len,-1);fft(x2,len,-1);
//		for (int j=0;j<len;j++) printf("%d ",x1[j]);cout<<endl;
//		//for (int i=0;i<=tot;i++) printf("%d ",x2[i]);cout<<endl;
//		cout<<endl;
//	}
	
	
	int ans=0;
	for (int i=0;i<=num;i++) ans=(ans+x1[i])%mod;
	printf("%d",1ll*ans*jc[tot-num]%mod*jc[num]%mod*jc[tot]%mod);
}