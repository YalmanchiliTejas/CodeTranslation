#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define lo long long 
#define inf 1000000000
#define md 1000000007
#define pb push_back
#define li 100005
using namespace std;
int n,x,y,par[li],dep[li],vis[li];
set<int> s[li];
pair<int,int> B[li];
vector<int> v[li];
void dfs(int node,int ata){
	par[node]=ata;
	dep[node]=(ata!=-1?dep[ata]+1:1);
	for(int i=0;i<(int)v[node].size();i++){
		int go=v[node][i];
		if(go==ata) continue;
		dfs(go,node);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
		s[x].insert(y);
		s[y].insert(x);
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++){
		B[i]=mp(dep[i],i);
	}
	sort(B+1,B+n+1,greater< pair<int,int> >());
	for(int i=1;i<=n;i++){
		int ind=B[i].se;
		if(vis[ind]==1) continue;
		int baba=par[ind];
		if((int)s[baba].size()>2){
			//printf("%d\n",ind);
			printf("First\n");
			return 0;
		}
		if((int)s[baba].size()==0 && vis[ind]==0){
			printf("First\n");
			return 0;
		}
		//printf("debug - >> %d\n",ind);
		int bb=par[baba];
		vis[ind]=1;
		vis[baba]=1;
		s[baba].erase(ind);
		s[ind].erase(baba);
		s[bb].erase(baba);
	}
	printf("Second\n");
	return 0;
}
