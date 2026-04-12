#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 1010;
const int mo = 1e+9+7;

LL f[N];
LL g[N][N],c[N][N];
int n,A,B,C,D;

LL quickmi(LL x,LL tim){
	LL ans=1;
	while(tim){
		if (tim%2)ans=ans*x%mo;
		x=x*x%mo;
		tim/=2;
	}
	return ans;
}

int main(){
	n=get();A=get();B=get();C=get();D=get();
	g[0][0]=1;
	c[0][0]=1;
	fo(i,1,n){
		c[i][0]=1;
		fo(j,1,i)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mo;
	}
	fo(i,1,n){
		g[i][0]=1;
		fo(j,1,n/i)
		g[i][j]=g[i][j-1]*c[i*j][i]%mo*quickmi(j,mo-2)%mo;
	}
	f[0]=1;
	fo(s,A,B)
		fd(i,n,1){
			fo(t,C,min(i/s,D))
			f[i]=(f[i]+f[i-s*t]*g[s][t]%mo*c[n-i+s*t][s*t])%mo;
		}
	printf("%lld\n",f[n]);
	return 0;
}