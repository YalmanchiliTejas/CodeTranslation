#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define ll long long
using namespace std;
vector<int> nex[114514];
int deg[114514],used[114514];
signed main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		nex[x].pb(y);
		nex[y].pb(x);
		deg[x]++;
		deg[y]++;
	}
	queue<int> que;
	for(int i=1;i<=n;i++){
		if(deg[i]==1){
			que.push(i);
		}
	}
	while(!que.empty()){
		int cur = que.front(); que.pop();
		if(used[cur]==0){
			for(int i=0;i<nex[cur].size();i++){
				int dur = nex[cur][i];
				if(used[dur]==0){
					used[cur]=dur;
					used[dur]=cur;
					deg[cur]=0;
					deg[dur]=0;
					for(int j=0;j<nex[dur].size();j++){
						if( deg [ nex[dur][j] ] >= 1){
							deg[ nex[dur][j] ]--;
						}
						if( deg[nex[dur][j]] == 1){
							que.push(nex[dur][j]);
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(used[i]==0){
			cout<<"First"<<endl;
			return 0;
		}
	}
	cout<<"Second"<<endl;
	return 0;
}