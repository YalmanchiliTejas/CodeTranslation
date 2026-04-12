#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define boost ios::sync_with_stdio(0); cin.tie(0);
#define int long long

const int N = 10;
const int MOD = 1e9 + 7;

bool vis[N];
vector<int> gr[N];
int n , m;
int cnt;
void dfs(int node , int par){
	// cout << node << "\n";

	vis[node] = true;
	
	// for(int i = 1 ; i <= n ; ++i){
	// 	cout << vis[i] << " ";
	// }cout << "\n";
	
	int end = 1;
	for(int i = 1 ; i <= n ; ++i){
		if(!vis[i]){
			end = 0;
			break;
		}
	}

	if(end)
		cnt++;

	for(auto i : gr[node]){
		if(i == par)
			continue;

		if(!vis[i]){
			dfs(i,node);
		}
	}

	vis[node] = false;
}
int32_t main(){
    boost;
    
    //code
    int x,y;
    cin >> n >> m;

    for(int i = 0 ; i < m ; ++i){
    	cin >> x >> y;
    	gr[x].push_back(y);
    	gr[y].push_back(x);
    }

    dfs(1,0);

    cout << cnt;
    return 0;
}