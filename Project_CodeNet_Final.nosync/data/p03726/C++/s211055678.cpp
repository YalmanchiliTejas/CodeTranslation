#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

const int MOD=998244353;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;

vector<int>E[200000];

int dfs(int v,int p){
	int cnt=0;
	for(int u:E[v]){
		if(u==p)continue;
		cnt+=dfs(u,v);
	}
	if(cnt>1){
		puts("First");exit(0);
	}
	return !cnt;
}

int main(){
	int n;cin>>n;
	rep(i,n-1){
		int a,b;scanf("%d%d",&a,&b);a--;b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	if(dfs(0,-1)){
		puts("First");
	}
	else puts("Second");
}