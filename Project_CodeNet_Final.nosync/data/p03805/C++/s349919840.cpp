#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define n_p(v) next_permutation(v.begin(),v.end())
#define to_ll(b) stoll(b)
#define MOD 1000000007
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

int dfs(vvi vec,int n,vector<bool> visited,int v)
{
	bool all_visited=true;
	
	rep(i,0,n){
		if(!visited[i]) all_visited=false;
	}
	if(all_visited) return 1;
	
	int ret=0;
	
	for(int c:vec[v]){
		if(visited[c]) continue;
		visited[c]=true;
		ret+=dfs(vec,n,visited,c);
		visited[c]=false;
	}
	return ret;
}

signed main(){
	int n,m; cin>>n>>m;
	vvi vec(n,vi(0));
	rep(i,0,m){
		int a,b; cin>>a>>b;
		--a; --b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	vector<bool> visited(n,false);
	visited[0]=true;
	cout<<dfs(vec,n,visited,0);
	return 0;
}