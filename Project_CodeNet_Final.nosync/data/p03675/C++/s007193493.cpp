#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const int N=2e5+11,INF=~0u>>2;
int n,a[N];
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
int main(){
//	freopen("ex.in","r",stdin);
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=n;i>=1;i-=2) printf("%d ",a[i]);
	for(int i=1+(n&1);i<=n-1;i+=2) printf("%d ",a[i]);
	return 0;
}