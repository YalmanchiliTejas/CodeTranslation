#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
const long long mod=1e9+7;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a,ll b){return a%b?gcd(b,a%b):b;}
ll lcm(ll c,ll d){return c*d/gcd(c,d);}
vector<vector<bool>> graph(8,vector<bool>(8,false));
int n,m;
int dfs(int v,vector<bool> visited){
	bool al_visited=true;
	for(int i=0;i<n;i++){
		if(!visited.at(i))al_visited=false;
	}
	if(al_visited)return 1;
	int res=0;
	for(int i=0;i<n;i++){
		if(!graph.at(v).at(i))continue;
		if(visited.at(i))continue;
		visited.at(i)=true;
        res+=dfs(i,visited);
		visited.at(i)=false;
	}
	return res;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		graph.at(a-1).at(b-1)=true;
		graph.at(b-1).at(a-1)=true;
	}
	vector<bool> visited(n,false);
	visited.at(0)=true;
	cout<<dfs(0,visited)<<endl;

}
