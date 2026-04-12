#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto pitr=c.begin();pitr!=c.end();++pitr){cout<<*pitr;if(next(pitr,1)!=c.end())cout<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;

constexpr ll atcoder_mod = 1e9+7;

template<typename T=int>
T in(){T x; cin >> x; return (x);}
template<typename T=int,typename C=vector<T>>
C vecin(int N){C x(N);REP(i,N){x[i]=in<T>();}return move(x);}

void vout(){cout << endl;}
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){cout << ' ' << h;vout(forward<Tail>(t)...);}
void out(){cout << endl;}
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){cout << h;vout(forward<Tail>(t)...);}

class ConnectNodeInfo{
	vector<vector<pair<ll,ll>>> graph;
public:
	ConnectNodeInfo(int node_num){
		graph.resize(node_num);
	}
	void AddNonDirectionalConnection(ll u,ll v,ll w){
		graph[u].emplace_back(v,w);
		graph[v].emplace_back(u,w);
	}
	void AddDirectionalConnection(ll u,ll v,ll w){
		graph[u].emplace_back(v,w);
	}
	vector<pair<ll,ll>>& operator[](ll index){
		return graph[index];
	}
	size_t size(){return graph.size();}
};

map<int,map<int,int>> W;

ll dfs(ConnectNodeInfo& connect,int child,int parent,ll dist){
	ll ans=dist;
	for(auto& x:connect[child]){
		if(x.first==parent) continue;
		if(x.second<0){
			int u=child,v=x.first;
			if(u>v) swap(u,v);
			x.second = dfs(connect,x.first,child,dist)+W[u][v];
		}
		ans = max(ans,x.second);
	}
	return ans;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int N=in();
	ConnectNodeInfo connect(N);
	REP(i,N-1){
		int u=in(),v=in(),w=in();
		connect.AddNonDirectionalConnection(u,v,-1);
		if(u>v) swap(u,v);
		W[u][v]=w;
	}
	
	vector<ll> H(N,0);
	REP(i,N){
		dfs(connect,i,-1,0);
	}

	REP(i,N){
		for(auto& x:connect[i]){
			H[i] = max(H[i],x.second);
		}
		out(H[i]);
	}
	return 0;
}

