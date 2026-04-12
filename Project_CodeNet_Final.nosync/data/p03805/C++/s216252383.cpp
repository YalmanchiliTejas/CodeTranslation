#include <bits/stdc++.h>

using namespace std;

const int N=1e6+3;

#define pb push_back
#define all(x) (x).begin(),(x).end()
typedef long long ll;

const int dx[]={1,-1,0,0},
		  dy[]={0,0,1,-1};

const int inf=1e9;

int n,m,a[N],b[N],k,q,u,x,y,tc,c,l,r,ans,p,cnt;

char s[N];

bool vis[8];

vector<int> g[8];

int dfs(int u,int vis,int d){
    if (d==n)
        return 1;
	int ans=0;
	vis|=(1<<u);
	for(auto v:g[u]){
        if (((1<<v) & vis) == 0)
            ans+=dfs(v,vis,d+1);
    }
	return ans;
}

int main(){
//	#ifndef ONLINE_JUDGE
//		freopen("test.txt","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		g[--u].push_back(--v);
		g[v].push_back(u);
	}
	printf("%d",dfs(0,0,1));
}
