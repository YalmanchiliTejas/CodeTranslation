#include<iostream>
#include <list>
#include<stack>
#include<queue>
#include <vector>
#include <set>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string>
#include <functional>

#define FOR(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define REP(i,n) FOR((i),0,(n))
#define LL long long
#define CLR(a) memset((a),0,sizeof(a))
#define SZ(x) (int((x).size()))
#define WAITING(str) int str;std::cin>>str;
#define DEBUGING(str) cout<<str<<endl
using namespace std;

const LL MOD = 1000000007;// 10^9+7
const int INF = (1 << 30);

class UnionFind {
public:
	vector<int>rank, parent;
	//初期化
	UnionFind(int size) {
		rank.resize(size, 0);
		parent.resize(size, 0);
		REP(i, size)parent[i] = i;
	}
	//木の根を求める
	int find(int x) {
		if (parent[x] == x)return x;
		else return parent[x] = find(parent[x]);
	}
	//xとyの属する集合を併合
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)return;
		if (rank[x] < rank[y])
			parent[x] = y;
		else {
			parent[y] = x;
			if (rank[x] == rank[y])rank[x]++;
		}
	}
	//xとyが同じ集合に属するか否か
	bool same(int x, int y) {
		return (find(x) == find(y));
	}
	//parentの内容を出力
	void debug() {
		for (auto num : parent) {
			cout << num << " ";
		}
		cout << "more:" << endl;
		REP(i, parent.size()) {
			cout << find(i) << " ";

		}
		cout << endl << "more:" << endl;
		for (auto num : parent) {
			cout << num << " ";
		}
		cout << endl;
	}
};

//変数
class Kruskal {
public:
	//引数：頂点数
	Kruskal(){}
	Kruskal(int size) :V(size), E(0) {}

	//u-v間の辺をcostで結びます
	void add_edge(int u, int v, int cost) {
		es.push_back({ u, v, cost });
		E++;
	}

	//クラスカル法を適用します
	LL kruskal() {
		sort(es.begin(), 
			es.end(), 
			[](const edge& e1, const edge& e2) { return e1.cost < e2.cost; }
		);//コストが小さい順にソート
		return kruskal_impl();
	}


private:
	struct edge {
		int u, v, cost;
	};

	bool comp(const edge& e1, const edge& e2) { return e1.cost < e2.cost; }
	int V, E;        //頂点数と辺数
	vector<edge> es; //辺


	LL kruskal_impl() const {
		UnionFind uf(V);
		LL res = 0;
		for (edge e : es) {
			if (!uf.same(e.u, e.v)) {
				uf.unite(e.u, e.v);
				res += e.cost;
			}
		}
		return res;
	}
};


int N;
vector<pair<int, int>>xy;
Kruskal kr;




//サブ関数
//入力
void input()
{
	cin >> N;
	kr = Kruskal(N);
	REP(i, N) {
		int x, y;
		cin >> x >> y;
		xy.push_back(make_pair(x, y));
	}
}



void make_road(vector<int> p) 
{
	vector<pair<int, int>> road;
	REP(i,(int) p.size()) {
		road.push_back(make_pair(p[i], i));
	}
	sort(road.begin(), road.end());

	REP(i, (int)road.size() - 1) {
		kr.add_edge(
			road[i].second, 
			road[i + 1].second, 
			abs(road[i].first - road[i + 1].first)
		);
	}
}



//計算
void calc()
{
	vector<int> xs;
	vector<int> ys;
	for (auto num : xy)xs.push_back(num.first);
	for (auto num : xy)ys.push_back(num.second);
	make_road(xs);
	make_road(ys);

}


//出力
void output()
{
	cout << kr.kruskal() << endl;
}


//デバッグ
void debug()
{
	int N;
	cin>>N;
}


//メイン関数
int main()
{
	input();
	calc();
	output();
	debug();
	
	return 0;
}
