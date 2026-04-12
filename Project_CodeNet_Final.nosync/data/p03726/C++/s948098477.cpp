#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
#define MN 100005
int n,d[MN];
struct edge{int to,nex;}e[MN*2];int hr[MN],cnt,fl[MN],fat[MN];
inline void ins(int f,int t){
	e[++cnt]=(edge){t,hr[f]};hr[f]=cnt;
}
inline void dfs1(int fa,int x){
	fl[x]=fl[fa]+1;fat[x]=fa;int res=0;
	for(int i=hr[x];i;i=e[i].nex) if(fa!=e[i].to) dfs1(x,e[i].to);
}
priority_queue<pair<int ,int> > que;
bool used[MN];
int main(){
	int a,b,i;
	n=read();
	for(i=1;i<n;i++) a=read(),b=read(),ins(a,b),ins(b,a),d[a]++,d[b]++;
	for(i=1;i<=n,d[i]==1;i++);dfs1(0,1);
	for(int i=1;i<=n;i++) que.push(make_pair(fl[i],i));
	while(!que.empty()){
		for(;!que.empty()&&used[que.top().second];que.pop());
		if(que.empty()) break;
		int top=que.top().second;
		int father=fat[top];que.pop();
		if(que.empty()){
			printf("First");return 0;
		}
		for(i=hr[father];i;i=e[i].nex) if(!used[e[i].to]&&e[i].to!=fat[father]&&e[i].to!=top){
			printf("First");return 0;
		}
		used[top]=1;used[father]=1;
	}
	printf("Second");
	return 0;
}