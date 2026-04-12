#include<bits/stdc++.h>

#define nxt(x) bian[x].nxt
#define ed(x) bian[x].ed

using namespace std;

const int maxn=1e6;

struct edge{
	int nxt,ed;
}bian[maxn];

int n;

int t[maxn],cnt=2;

int w[maxn];

bool bl[maxn];

void lj(int x,int y) {
	ed(cnt)=y;
	nxt(cnt)=t[x];
	t[x]=cnt++;
	w[x]++;
}

queue<int> q;

void bfs() {
	while(!q.empty()) q.pop();
	
	for (;;) {
		bool wy=0;
		for (int l=1;l<=n;l++) {
			if (w[l]==1&&bl[l]==0) {
				q.push(l);
			}
		}
		while(!q.empty()) {
			int u=q.front();
			q.pop();
			for (int l=t[u];l;l=nxt(l)) {
				int v=ed(l);
				if (bl[v]==1||w[v]!=2) continue;
				for (int j=t[v];j;j=nxt(j)) {
					int x=ed(j);
					w[x]--;
					if (w[x]==1&&bl[x]==0) q.push(x);
				}
				bl[u]=bl[v]=1;
				wy=1;
			}
		}
		if (wy==0) break;
	}
}

int main() {
	cin>>n;
	for (int l=1;l<n;l++) {
		int u,v;
		cin>>u>>v;
		lj(u,v);
		lj(v,u);
	}
	bfs();
	int ans=0;
	for (int u=1;u<=n;u++) {
		if (bl[u]==0) {
			ans++;
		}
	}
	if (ans!=2) cout<<"First"<<endl;
	else cout<<"Second"<<endl;

}
