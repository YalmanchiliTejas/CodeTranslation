#include<bits/stdc++.h>
using namespace std;
template<typename T>inline T read(){
	T x=0,f=0;char c=getchar();
	while(!isdigit(c)) f=c=='-',c=getchar();
	while(isdigit(c)) x=x*10+c-48,c=getchar();
	return f?-x:x;
}
namespace run{
	const int N=3009,mod=998244353;
	inline int add(int x,int y){return x+y>=mod?x-mod+y:x+y;}
	inline int sub(int x,int y){return x>=y?x-y:x+mod-y;}
	int n,s,a[N],g[N];
	int main(){
		n=read<int>(),s=read<int>();
		for(int i=1;i<=n;i++) a[i]=read<int>();
		int ans=0;
		for(int j=1;j<=n;j++){
			for(int i=s;i>=a[j];i--)
				g[i]=add(g[i],g[i-a[j]]);
			g[a[j]]=add(g[a[j]],j);
			ans=add(ans,g[s]);
		}
		printf("%d\n",ans);
		return 0;
	}
}
int main(){
#ifdef my
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	return run::main();
}