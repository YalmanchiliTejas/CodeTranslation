#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<utility>
#include<numeric>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<tuple>
#include<stack>
#include<queue>
#include<functional>
#include<iterator>
#include<cmath>
#include<cctype>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF = 1e9;
const ll LINF = 1e18;

struct edge{int to,cost;};


vector<int> es[8]; //es[a][i] = b; a->b存在
bool checked[8];
int n,ans=0;

void dfs(int from){
	//checked[from] = true;
	bool hasNext=false;
	for(int i=0;i<es[from].size();i++){
		int to = es[from][i];
//		cout << "\t" << from << "->" << to << "\n";
		if(!checked[to]){
			hasNext=true;
			checked[to] = true;
//			cout << "dfs(" << to << ")\n";
			dfs(to);
			checked[to] = false;
		}
	}
	if(!hasNext){
//		cout << from << " has no next\n";
		for(int i=0;i<n;i++){
			if(!checked[i]) return;
		}
		ans++;
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m;
	cin >> n >> m;

	int a,b;
	for(int i=0;i<m;i++){
		cin >> a >> b;
		a--;b--;
		es[a].push_back(b);
		es[b].push_back(a);
	}
	checked[0]=true;
	dfs(0);

	cout << ans << "\n";
	
	return 0;
}