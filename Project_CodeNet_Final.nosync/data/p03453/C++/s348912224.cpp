#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdint>
using namespace std;

const int64_t INF = 4611686018427387903; // 10^62-1、使わない辺とかに用いる
const int MOD = 1000000007; // 今回使う余り
const int MAX = 200001;

typedef struct node {
	int myID; // ユニークID, まぁデバッグ用？
	vector<pair<int, int> > edge; // 移動辺
	vector<int64_t> costs; // 確定したコスト
	bool done; // 確定ノードか否か
	int64_t cost; // 現時点のコスト
	
	bool operator<(const node& a) const {
		return cost > a.cost;
	}
} Node;

typedef class dijkstra {
	private:
		int N; // 頂点数
		vector<Node> node;
		void init(int s);
	public:
		dijkstra(int n);
		void addEdge(int n, int m, int cost);
		void calc(int s);
		int64_t getCost(int s, int t);
		vector<pair<int64_t, int> > getNode(int s);
		vector<pair<int, int> > getEdge(int s);
} Dijkstra;

/**
 * 頂点数を渡してください、初期化します。
 * @param n 頂点の数
 */
dijkstra::dijkstra(int n) {
	N = n;
	node.resize(n);
	for (int i = 0;i < N;i ++) {
		node[i].edge.clear();
		node[i].myID = i;
	}
}

/**
 * 頂点nと頂点mの間にcostの重み付き無向辺を作ります。
 * @param n 行く側の頂点
 * @param m 向かう側の頂点
 * @param cost 移動コスト
 */
void dijkstra::addEdge(int n, int m, int cost) {
	node[n].edge.push_back(make_pair(m, cost));
	node[m].edge.push_back(make_pair(n, cost));
}

void dijkstra::init(int s) {
	for (int i = 0;i < N;i ++) {
		node[i].done = false;
		node[i].cost = INF;
	}
	node[s].cost = 0;
}

/**
 * ダイクストラ法を実行します。O(E+VlogV)です。
 */
void dijkstra::calc(int s) {
	init(s);
	priority_queue<Node> que;
	Node check;
	for(que.push(node[s]);!que.empty();) {
		check = que.top();
		que.pop();
		if (check.done) continue;
		check.done = true;
		for (int i = 0;i < check.edge.size();i ++) {
			if (check.cost + check.edge[i].second < node[check.edge[i].first].cost) { // より近い経路発見！
				node[check.edge[i].first].cost = check.cost + check.edge[i].second;
				que.push(node[check.edge[i].first]);
			}
		}
	}
	node[s].costs.resize(N);
	for (int i = 0;i < N;i ++) node[s].costs[i] = node[i].cost;
}

/**
 * 頂点sから頂点tへ行くまでの最短コストを返します。
 * @param s 始点となる頂点
 * @param t 終点となる頂点
 * @return sからtまでの最短コスト
 */
int64_t dijkstra::getCost(int s, int t) {
	return node[s].costs[t];
}

vector<pair<int64_t, int> > dijkstra::getNode(int s) {
	vector<pair<int64_t, int> > ret;
	for (int i = 0, l = node[s].costs.size();i < l;++ i) {
		ret.push_back(make_pair(node[s].costs[i], i));
	}
	return ret;
}

vector<pair<int, int> > dijkstra::getEdge(int s) {
	return node[s].edge;
}

int main() {
	int N, M, S, T, U, V, D;
	cin >> N >> M >> S >> T;
	Dijkstra graph(M);
	for (int i = 0;i < M;i ++) {
		cin >> U >> V >> D;
		graph.addEdge(U - 1, V - 1, D);
	}
	graph.calc(S - 1);
	graph.calc(T - 1);
	vector<pair<int64_t, int> > sDist = graph.getNode(S - 1);
	sort(sDist.begin(), sDist.end());
	
	int64_t dist = graph.getCost(S - 1, T - 1); // 最短距離
	static int64_t dp1[MAX], dp2[MAX];
	
	dp1[S - 1] = 1, dp2[T - 1] = 1;
	for (int i = 1;i < N;i ++) {
		dp1[sDist[i].second] = 0;
		vector<pair<int, int> > edge = graph.getEdge(sDist[i].second);
		for (int j = 0, l = edge.size();j < l;j ++) {
			if (graph.getCost(T - 1, sDist[i].second) + edge[j].second + graph.getCost(S - 1, edge[j].first) == dist) { // 前に出てきた最短経路が1つ
				dp1[sDist[i].second] += dp1[edge[j].first];
				dp1[sDist[i].second] %= MOD;
			}
		}
		if (sDist[N - i - 1].second == T - 1) continue;
		dp2[sDist[N - i - 1].second] = 0;
		edge = graph.getEdge(sDist[N - i - 1].second);
		for (int j = 0, l = edge.size();j < l;j ++) {
			if (graph.getCost(S - 1, sDist[N - i - 1].second) + edge[j].second + graph.getCost(T - 1, edge[j].first) == dist) { // 前に出てきた最短経路が1つ
				dp2[sDist[N - i - 1].second] += dp2[edge[j].first];
				dp2[sDist[N - i - 1].second] %= MOD;
			}
		}
	}
	
	int64_t ans = dp1[T - 1] * dp1[T - 1] % MOD;
	for (int i = 0;i < N;i ++) {
		if (graph.getCost(S - 1, i) * 2 == dist && graph.getCost(S - 1, i) == graph.getCost(T - 1, i)) { // 丁度半分の距離の頂点=出会う可能性がある
			ans = (ans - dp1[i] * dp1[i] % MOD * dp2[i] % MOD * dp2[i] % MOD + MOD) % MOD;
		}
		vector<pair<int, int> > edge = graph.getEdge(i);
		for (int j = 0, l = edge.size();j < l;j ++) {
			if (graph.getCost(T - 1, i) * 2 < dist && graph.getCost(S - 1, edge[j].first) * 2 < dist && graph.getCost(T - 1, i) + edge[j].second + graph.getCost(S - 1, edge[j].first) == dist) { // 辺が半分の距離に属する=出会う可能性がある
				ans = (ans - dp1[edge[j].first] * dp1[edge[j].first] % MOD * dp2[i] % MOD * dp2[i] % MOD + MOD) % MOD;
			}
		}
	}
	cout << ans;
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり
また、コンテスト後に https://31536000.hatenablog.com/ で解説していると思うので、良かったら読んでねー

まず、最短経路しか通らないので予め最短経路を求めておく
その時、ある頂点について考えると、その1個前の頂点の最短移動経路の移動方法の総和に等しい(最短経路なので重複はしないはず)
ということは、速く着く頂点から順番に動的計画法を用いて何通りか求められる

さて、問題はここから
どうやって重複する経路を数えるか？という問題が発生する
まず、単純に最短経路の個数ならdp1[T - 1] * dp2[S - 1]通り
ここから、同じ頂点で出会う可能性と辺で出会う可能性を考えてみる
ある頂点で出会うとして、それはその頂点までの移動時間が同じ
つまり丁度最短距離の半分の位置の頂点だね
その頂点をvとしてdp1[v]^2dp2[v]^2通り、かな
次に、辺で出会う場合
これは同様に半分の位置が辺だった、ということなので
頂点をv, v2としてdp1[v]^2dp2[v2]^2か？

*/