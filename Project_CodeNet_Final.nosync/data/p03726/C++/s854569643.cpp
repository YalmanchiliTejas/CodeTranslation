
// in the name of god 
// vaght hast vali kam ast !

#include <bits/stdc++.h>
using namespace std ;

const int MAXN = 1e6 + 100 ;

int sz[MAXN] ; 
vector<int> ver[MAXN] ;
void dfs(int v , int par = 0){
	sz[v] = 1 ; 
	int tmp = 0 ; 
	for(auto u : ver[v]){
		if(u == par)continue ; 
		dfs(u , v) ; 
		tmp += sz[u] % 2 ; 
		sz[v] += sz[u] ; 
	}
	if(tmp > 1){cout << "First" ; exit(0) ; }
}
int32_t main(){
	ios_base::sync_with_stdio(0) ;
	cin . tie(0) ; cout . tie(0) ; 

	int n ; cin >> n ;  

	for(int i = 1 ; i < n ; i ++){
		int x , y ; cin >> x >> y ; 
		x -- , y -- ; 
		ver[x] . push_back(y) ; 
		ver[y] . push_back(x) ; 
	}
	if(n % 2) return cout << "First" , 0; 
	dfs(0) ; 
	cout << "Second" ; 
}