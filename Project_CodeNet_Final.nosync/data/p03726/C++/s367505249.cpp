#include <stdio.h>
#include <string.h>
#define MN 200000
int n,cnt=0;
bool e[MN+5];
int d[MN+5],hd[MN+5],to[MN+5],nxt[MN+5],rn=0;
struct STACK{
	int tp,m[MN+5];
	STACK(){tp=0;}
	bool empty(){return tp==0;}
	int top(){return m[tp];}
	void push(int x){m[++tp]=x;}
	void pop(){--tp;}
}s;
inline void add(int u,int v){
	++rn; d[u]++;
	nxt[rn]=hd[u],hd[u]=rn;
	to[rn]=v;
}
int main(){
	memset(hd,0xff,sizeof(hd));
	memset(d,0,sizeof(d));
	memset(e,true,sizeof(e));
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;i++){
		if(d[i]==1)s.push(i);
	}
	while(!s.empty()){
		int u=s.top(); s.pop();
//		printf("d %d %d\n",u,d[u]);
		if((!e[u])||(d[u]<=0))continue;
//		printf("del %d\n",u);
		e[u]=false; cnt++;
		for(int i=hd[u];i!=-1;i=nxt[i]){
			if((!e[to[i]])||(d[to[i]]<=0))continue;
//			printf("del %d-%d\n",u,to[i]);
			e[to[i]]=false; cnt++;
			for(int j=hd[to[i]];j!=-1;j=nxt[j]){
//				printf("spread %d-%d\n",to[i],to[j]);
				d[to[j]]--;
				if(d[to[j]]==1)s.push(to[j]);
			}
		}
	}
	puts(cnt==n?"Second":"First");
}