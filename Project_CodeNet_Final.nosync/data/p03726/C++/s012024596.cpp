#include<bits/stdc++.h>

using namespace std;

const int MAXN=1e5+7;

struct side {
	int from,to,nex;
}edge[MAXN<<1];
int head[MAXN],cntm=0;
void link(int from,int to) {
	edge[++cntm].from=from;
	edge[cntm].to=to;
	edge[cntm].nex=head[from];
	head[from]=cntm;
}

int n;
int col[MAXN],siz[MAXN];
int ans=0;

void dfs(int now,int fa) {
	siz[now]=1;
	for(int i=head[now];i;i=edge[i].nex) {
		if(edge[i].to!=fa) {
			dfs(edge[i].to,now);
			siz[now]+=siz[edge[i].to];
		}
	}
	if(siz[now]==1) return;
	int cnt=0;
	for(int i=head[now],v;i;i=edge[i].nex) {
		v=edge[i].to;
		if(v==fa) continue;
		if(!col[v]) cnt++;
	}
	if(cnt==1) col[now]=1;
	if(cnt>1) ans=1;
	if(now==1&&cnt==0) ans=1;
}

int main() {
	cin>>n;
	for(int i=1,i1,i2;i<n;i++) {
		cin>>i1>>i2;
		link(i1,i2);
		link(i2,i1);
	}
	dfs(1,0);
	if(ans) cout<<"First"<<endl;
	else cout<<"Second"<<endl;
}