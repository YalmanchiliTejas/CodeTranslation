#include <bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int gi(){
    char ch=getchar(); int x=0,q=0;
    while(ch<'0'||ch>'9') q=ch=='-'?1:q,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return q?-x:x;
}
int head[N],nn[N<<1][2],f[N],cnt;
#define link(u,v) (nn[++cnt][1]=v,nn[cnt][0]=head[u],head[u]=cnt)
void dfs(int x,int fa){
    f[x]=2;
    for (int i=head[x],y; i; i=nn[i][0])
	if ((y=nn[i][1])!=fa){
	    dfs(y,x);
	    if (f[y]==1) continue;
	    if (!f[y]) f[x]=0;
	    else{
		if (f[x]==2) f[x]=1;
		else f[x]=0;
	    }
	}
    return;
}
int main(){
    int n=gi(),a,b;
    for (int i=2; i<=n; ++i)
	a=gi(),b=gi(),link(a,b),link(b,a);
    dfs(1,0);
    if (f[1]!=1) cout<<"First";
    else cout<<"Second";
    return 0;
}
