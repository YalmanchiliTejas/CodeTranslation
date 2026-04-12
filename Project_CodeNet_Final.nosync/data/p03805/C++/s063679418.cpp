#include <iostream>
using namespace std;
bool gra[9][9],vis[9];
int m,ans;
void dfs(int i){
//	cout << i <<endl;
//	for(int j =1;j<=m;++j)cout<<vis[j]<<" ";
//	cout<<endl<<endl;
	bool f=1;
	for (int ii = 1;ii<=m;++ii)if (!vis[ii])f=0;
	if (f){
		ans++;
		return ;
	}
	for (int ii =1;ii<=m;++ii){
		if (gra[i][ii]&&(!vis[ii])&&i!=ii){
			vis[ii]=1;
			dfs(ii);
			vis[ii]=0;
		}
	}
}

int main(){
	int n;
	cin >> m >> n;
	for(int i =1;i<=n;++i){
		int a,v;
		cin >> a>>v;
		gra[a][v]=gra[v][a] =1;
	}
	vis[1]=1;
	dfs(1);
	cout<<ans<<endl;
}