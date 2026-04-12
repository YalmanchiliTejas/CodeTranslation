#include<iostream>
#include<vector>
using namespace std;

int n,m,u,v,ans;
vector<int> a[10];
int f[10];

void dfs(int p,int q){
	f[q]=1;
	if (p==n) ans++;
	else{
		for (int i=0;i!=a[q].size();i++){
			if (f[a[q][i]]==0){
				dfs(p+1,a[q][i]);
				f[a[q][i]]=0;
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i=1;i<=m;i++){
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i=1;i<=n;i++) f[i]=0;
	ans=0;
	dfs(1,1);
	cout << ans << endl;
	return 0;
}