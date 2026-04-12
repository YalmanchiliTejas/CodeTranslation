#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 6;
vector < int > nxt[_]; int N , cnt;

int dfs(int x , int p){
	int lft = 1;
	for(auto t : nxt[x])
		if(t != p && dfs(t , x) && lft){++cnt; lft = 0;}
	return lft;
}

int main(){
	cin >> N; for(int i = 1 ; i < N ; ++i){int p , q; cin >> p >> q; nxt[p].push_back(q); nxt[q].push_back(p);}
	dfs(1 , 0); cout << (cnt * 2 == N ? "Second" : "First");
	
	return 0;
}
