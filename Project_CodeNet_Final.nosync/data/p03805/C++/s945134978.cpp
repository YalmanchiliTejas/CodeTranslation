#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=0;
vector<int> adjl[9];
bool visited[9];
void dfs(int x){
	visited[x]=true;
	for(int i : adjl[x]){
		if(!visited[i]){
			dfs(i);
		}

			
		
	}
	bool flag=true;
			for(int j=1;j<=n;j++){
				if(!visited[j]){
					flag=false;
				}
			}
			if(flag){
				//cout<<x<<endl;
				ans++;
			}
	visited[x]=false;
}

int main(){
	cin>>n>>m;
	visited[0]=true;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adjl[a].push_back(b);
		adjl[b].push_back(a);
	}
	dfs(1);
	cout<<ans<<endl;

}