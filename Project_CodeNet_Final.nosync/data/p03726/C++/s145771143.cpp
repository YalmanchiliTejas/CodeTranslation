#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int fir[100010],dis[200010],nxt[200010],id;
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
bool flg;
bool dfs(int x,int fa=-1){
	int sum=0;
	for(int i=fir[x];i;i=nxt[i]){
		if(dis[i]==fa)continue;
		sum+=dfs(dis[i],x);
	}
	if(sum>1)flg=1;
	return!sum;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),a,b;
	for(int i=1;i<n;++i)a=gi(),b=gi(),link(a,b),link(b,a);
	flg|=dfs(1);
	if(flg)puts("First");
	else puts("Second");
	return 0;
}
