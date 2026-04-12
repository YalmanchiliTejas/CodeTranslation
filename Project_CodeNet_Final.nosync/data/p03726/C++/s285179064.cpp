#include<bits/stdc++.h>
using namespace std;
#define N 1111116
#define next nxt

int n,x[N],y[N],next[N],p[N],f[N];

int travel(int x){
	int ans=0;
	for (int t=p[x];t;t=next[t])
		if (y[t]!=f[x])
		f[y[t]]=x,ans+=travel(y[t]);
	return ans^1;
}

int read(){
	int x=0,f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-f;
	for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main(){
	n=read();
	for (int i=1;i<=n-1;i++){
		x[2*i-1]=y[2*i]=read();
		y[2*i-1]=x[2*i]=read();
		next[2*i-1]=p[x[2*i-1]];p[x[2*i-1]]=2*i-1;
		next[2*i]=p[x[2*i]];p[x[2*i]]=2*i;
	}
	printf(travel(1)?"First\n":"Second\n");
	return 0;
}