#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>g;

int dfs(int cur,int depth){
	if(depth==g.size())return 1;
	int res=0,temp=-1,temp2=-1;
	for(auto&&i:g.at(cur)){
		if(g.at(i).front()==-1)continue;
		swap(temp,i);
		swap(temp2,g.at(cur).front());
		res+=dfs(temp,depth+1);
		swap(temp2,g.at(cur).front());
		swap(temp,i);
	}
	return res;
}

int main(){
	cin.tie(0),ios::sync_with_stdio(false);
	int n,m; cin>>n>>m;
	g.resize(n);
	for(int i=0;i<m;++i){
		int a,b; cin>>a>>b; --a,--b;
		g.at(a).emplace_back(b);
		g.at(b).emplace_back(a);
	}
	cout<<dfs(0,1)<<"\n"s;
}
