#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
#define rep(val,cnt) for(int (val)=0;(val)<(cnt);++(val))
#define all(v) (v).begin(),(v).end()
using namespace std;

using pint = pair<int,int>;
using tint = tuple<int,int,int>;

void Main(void);
signed main(void){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	Main();
}

template<typename T>
struct edge{T to,cost;};

template<typename T>
class Graph{
	public :
	vector<vector<edge<T>>> graph;

	void add(int from,T to,int cost){
		graph[from].emplace_back((edge<T>){to,cost});
	}
	T prim(void){
		using Pi = pair<T,int>;
		T total=0;
		vector<bool> used(graph.size(),false);
		priority_queue<Pi,vector<Pi>,greater<Pi>> que;
		que.emplace(0,0);
		while(!que.empty()){
			auto p=que.top(); que.pop();
			if(used[p.second]) continue;
			used[p.second]=true;
			total+=p.first;
			for(auto &e : graph[p.second]) que.emplace(e.cost,e.to);
		}
		return total;
	}
};

void Main(void){
	int N; cin>>N;
	vector<tint> PX,PY;
	rep(i,N){
		int x,y; cin>>x>>y;
		PX.emplace_back(x,y,i),PY.emplace_back(y,x,i);
	}
	sort(all(PX)),sort(all(PY));
	Graph<int> gr; gr.graph.resize(N);
	for(int i=1;i<N;++i){
		int x1,y1,p1,x2,y2,p2,dist;
		tie(x1,y1,p1)=PX[i-1],tie(x2,y2,p2)=PX[i];
		dist=min(abs(x1-x2),abs(y1-y2));
		gr.add(p1,p2,dist),gr.add(p2,p1,dist);
		tie(x1,y1,p1)=PY[i-1],tie(x2,y2,p2)=PY[i];
		dist=min(abs(x1-x2),abs(y1-y2));
		gr.add(p1,p2,dist),gr.add(p2,p1,dist);
	}
	cout<<gr.prim()<<endl;
}