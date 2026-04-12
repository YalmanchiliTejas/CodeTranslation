// #includes {{{
#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define RREP(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define LET(x,a) __typeof(a) x(a)
//#define IFOR(i,it,c) for(__typeof((c).begin())it=(c).begin();it!=(c).end();++it,++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair

#define EXIST(e,s) ((s).find(e)!=(s).end())

#define RESET(a) memset((a),0,sizeof(a))
#define SET(a) memset((a),-1,sizeof(a))
#define PB push_back
#define DEC(it,command) __typeof(command) it=command

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define debug2(x) cerr << #x << " = [";REP(__ind,(x).size()){cerr << (x)[__ind] << ", ";}cerr << "] (L" << __LINE__ << ")" << endl;

const int INF=0x3f3f3f3f;

typedef long long Int;
typedef unsigned long long uInt;
typedef long double rn;

typedef pair<int,int> pii;

/*
#ifdef MYDEBUG
#include"debug.h"
#include"print.h"
#endif
*/
// }}}

//{{{ Graph
typedef int Weight;
struct Edge {
	int src, dst, rev;
	Weight weight;
	Edge(int src, int dst, Weight weight=1,int rev=-1) :
		src(src), dst(dst), weight(weight), rev(rev) { }
};
bool operator < (const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
		e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
//typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

struct Graph:vector<Edges>{
	Graph(){}
	Graph(const int &n){this->assign(n,Edges());}
	//add bi-directional edge
	void addBiEdge(int from ,int to, Weight w=1){
		while(this->size()<max(from,to)+1)this->push_back(Edges());
		this->at(from).push_back(Edge(from,to,w,this->at(to).size()));
		this->at(to).push_back(Edge(to,from,w,this->at(from).size()-1));
	}
	//add directional edge
	void addEdge(int from ,int to, Weight w=1){
		while(this->size()<from+1)this->push_back(Edges());
		this->at(from).push_back(Edge(from,to,w));
	}
};
#ifdef DEBUG
#include"graph/graphviz.h"
#endif
//}}}

//{{{ bipartite Match (hopcroft karp)
bool augment(const Graph &g,int left,const int &n,vector<bool> &visited,vector<int> &levels,vector<int> &matching) {
	if (left == n)return true;
	if (visited[left])return false;
	visited[left] = true;
	REP(i, g[left].size()) {
		int right = g[left][i].dst;
		int next = matching[right];
		if (levels[next] > levels[left] && augment(g,next,n,visited,levels,matching)) {
			matching[right] = left;
			return true;
		}
	}
	return false;
}

int bipartiteMatching(const Graph &g,int n,int m,Edges &ans) {
	vector<bool> matched(n,false),visited;
	vector<int> levels,matching(m,n);
	bool cont;
	do {
		levels.assign(n+1, -1);
		levels[n] = n;
		queue<int> q;
		REP(left, n) {
			if (!matched[left]) {
				q.push(left);
				levels[left] = 0;
			}
		}
		while(!q.empty()) {
			int left = q.front();
			q.pop();
			REP(i, g[left].size()) {
				int right = g[left][i].dst, next = matching[right];
				if (levels[next] < 0) {
					levels[next] = levels[left] + 1;
					q.push(next);
				}
			}
		}
		visited.assign(n, false);
		cont = false;
		REP(left, n)
			if (!matched[left] && augment(g,left,n,visited,levels,matching))
				matched[left] = cont = true;
	} while(cont);
	ans.clear();
	REP(i,m)if(matching[i]!=n)ans.push_back(Edge(matching[i],i));
	return count(ALL(matched), true);
}
//}}}

int N;

void dfs(int u,const Graph &g, vector<int> &col,int p=-1,int c=0){
	col[u] = c;
	FOR(e,g[u]){
		if(e->dst==p)continue;
		if(col[e->dst]!=-1)continue;
		dfs(e->dst,g,col,u,1-c);
	}
}

int main(){
	cin>>N;
	Graph g(N);
	REP(i,N-1){
		int a,b;
		cin>>a>>b;
		a--;b--;
		g.addBiEdge(a,b);
	}
	vector<int> col(N,-1);
	dfs(0,g,col);
	vector<int> zero, one;
	unordered_map<int,int> zero_id, one_id;
	REP(u,N){
		if(col[u]==0){
			int t = zero_id.size();
			zero_id[u] = t;
		}else{
			int t = one_id.size();
			one_id[u] = t;
		}
	}
	Graph g2(zero_id.size());
	REP(u,N){
		if(col[u]==0){
			FOR(e,g[u])g2.addEdge(zero_id[u],one_id[e->dst]);
		}
	}
	Edges ans;
	bipartiteMatching(g2,zero_id.size(),one_id.size(),ans);
	if(ans.size()==zero_id.size() and ans.size()==one_id.size()){
		cout<<"Second"<<endl;
	}else{
		cout<<"First"<<endl;
	}
	return 0;
}
