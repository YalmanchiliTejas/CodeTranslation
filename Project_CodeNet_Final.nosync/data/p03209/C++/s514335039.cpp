#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<cstdio>
#include<vector>
#include<climits>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
LL read(){
	LL f=1,x=0;char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f*x;
}
#define MAXN 50
#define INF 0x3f3f3f3f
LL f[MAXN+5],g[MAXN+5];
LL Fuc(LL n,LL k){
	if(!k) return 0;
	if(!n||k==g[n]) return f[n];
	if(k==g[n-1]+2)
		return Fuc(n-1,k-2)+1;
	else if(k<g[n-1]+2)
		return Fuc(n-1,k-1);
	return f[n-1]+1+Fuc(n-1,k-g[n-1]-2);//f[n-1]+2<k
}
int main(){//f[i]:等级为i的汉堡有f[i]片肉
	LL n=read(),k=read();
	g[0]=f[0]=1;
	for(int i=1;i<=n;i++)
		f[i]=2*f[i-1]+1,g[i]=2*g[i-1]+3;
	printf("%lld\n",Fuc(n,k));
	return 0;
}
