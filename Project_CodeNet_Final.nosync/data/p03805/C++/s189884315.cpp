#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto& x:c){cout<<x<<' ';}cout<<endl;

constexpr int atcoder_mod = 1e9+7;

using namespace std;
using ll = long long;

template<typename T=int>
T in(){T x; cin >> x; return (x);}

class ConnectNodeInfo{
	vector<vector<pair<ll,ll>>> graph;
public:
	ConnectNodeInfo(int node_num){
		graph.resize(node_num);
	}
	void AddConnection(ll u,ll v,ll w){
		graph[u].emplace_back(v,w);
		graph[v].emplace_back(u,w);
	}
	vector<pair<ll,ll>>& operator[](ll index){
		return graph[index];
	}
	size_t size(){return graph.size();}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N=in(),M=in();
	ConnectNodeInfo connection(N);
	REP(i,M){
		int u=in(),v=in();
		connection.AddConnection(u-1,v-1,1);
	}
	vector<int> C(N-1);
	iota(ALL(C),1);
	ll sum = 0;
	do{
		bool connect = true;
		int prev = 0;
		for(auto& x:C){
			if(find_if(ALL(connection[prev]),[&](const pair<ll,ll>& lhs){return lhs.first==x;})==connection[prev].end()){
				connect = false;
				break;
			}
			prev = x;
		}
		if(connect) sum++;
	}while(next_permutation(ALL(C)));

	cout << sum << endl;
	return 0;
}
