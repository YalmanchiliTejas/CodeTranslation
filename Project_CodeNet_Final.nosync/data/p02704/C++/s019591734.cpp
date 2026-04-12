#include<iostream>
#include<string>

void solve_A() {
	int S, W;
	std::cin >> S >> W;
	//std::string result = (S <= W ? "unsafe" : "safe");
	std::cout << (S <= W ? "unsafe" : "safe") << std::endl;
}

void solve_B() {
	int A, B, C, D;
	std::cin >> A >> B >> C >> D;
	while (!( A <= 0 || C <= 0)) {
		C -= B;
		if (C <= 0) break;
		A -= D;
	}
	std::cout << (A <= 0 ? "No" : "Yes") << std::endl;
}

#include<vector>
#include<algorithm>

void solve_C() {
	int N;
	std::vector<std::string> v;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::string tmp;
		std::cin >> tmp;
		v.push_back(tmp);
	}
	std::sort(v.begin(), v.end());
	auto last = std::unique(v.begin(), v.end());
	v.erase(last, v.end());
	std::cout << v.size() << std::endl;

}

#include<set>

void solve_C2() {
	int N;
	std::set<std::string> st;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::string s;
		std::cin >> s;
		st.insert(s);
	}
	std::cout << st.size() << std::endl;
}

void solve_D() {//TLE
	std::string S;
	std::cin >> S;
	int N = S.length();
	int ans = 0;
	for (int i = 0; i < N-3; i++) {
		for (int j = i+3; j < N; j++) {
			int num = atoi(S.substr(i, j - i+1).c_str());
			if (num % 2019 == 0) {
				ans++;
			}
		}
	}
	std::cout << ans << std::endl;
}

void solve_D2() {//類題158E
	std::string s;
	std::cin >> s;
	int n = s.size();
	std::reverse(s.begin(), s.end());
	int x = 1, ans = 0, total = 0;//累積和
	const int m = 2019;
	std::vector<int> cnt(m);
	for (int i = 0; i < n; i++) {
		cnt[total]++;
		total += atoi(s.substr(i, 1).c_str()) * x; //N桁までの値 = N桁目の値 * 10^N + N-1桁目の値
		total %= m; //N桁までの値のmod = (N桁 + (N-1~1)桁目のmod) mod 2019
		ans += cnt[total];//計算したN桁の累積和のmodの値が1~N-1桁までで計算したmodと一致する場合、区間の数値のmodが0と同値
		//modが一致する個数の部分数列を新たに作成できるので、cnt配列の要素分足し合わせる
		x = x * 10 % m;
	}
	std::cout << ans << std::endl;
}

void solve_D3() {
	std::string s;
	std::cin >> s;
	int n = s.length();
	const int N = 200000;
	std::reverse(s.begin(), s.end());
	long long int x = 1, ans = 0;
	long long int total[N];//累積和
	total[0] = 0;
	const int m = 2019;
	std::vector<int> cnt(m);
	for (int i = 1; i <= n; i++) {
		total[i] = total[i-1] + atoi(s.substr(i, 1).c_str()) * x;
		x = x * 10;
		for (int j = 1; j < i-3; j++) {
			if ((total[i] - total[j])%2019 ==0) {
				ans++;
			}
		}
	}
	std::cout << ans << std::endl;
}

#include<queue>
const int MAX_V = 50;
const int MAX_S = MAX_V * 50;
const long long INF = 1e18;

struct Edge {
	int to, a, b;
	Edge(int to, int a, int b) :to(to), a(a), b(b) {}//コンストラクタ
};

struct Node {
	int v, s;//頂点、所持金
	long long x;//所要時間
	Node(int v, int s, long long x) :v(v), s(s), x(x) {}
	bool operator < (const Node& a) const { return x > a.x; }//最小ヒープにする。移動時間最小時間を得ることで探索の効率をよくする
};

std::vector<Edge> g[MAX_V];//隣接リスト
long long dp[MAX_V][MAX_S+1];

void solve_E() {
	int n, m, s;
	std::cin >> n >> m >> s;
	for (int i = 0; i<m; i++) {
		int u, v, a, b;
		std::cin >> u >> v >> a >> b;
		u--; v--;
		g[u].emplace_back(v, a, b);
		g[v].emplace_back(u, a, b);//双方向のノードの定義
	}
	std::vector<int> c(n), d(n);
	for (int i = 0; i < n; i++) {
		std::cin >> c[i] >> d[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < MAX_S+1; j++) {
			dp[i][j] = INF;
		}
	}
	s = std::min(s, MAX_S);//ここが重要。消費する銀貨の最大値はA_max * (N_max - 1) = 50 * 49 = 2500
	//入力される銀貨がどんなに大きくてもここで最大値に丸める。そのあと、都市と銀貨の数について動的計画法を用いて最小の移動時間を計算する

	std::priority_queue<Node> q;
	auto push = [&]/*ラムダキャプチャ*/(int v, int s, long long x) {//ある地点にある所持金である時間で到達できる
		if (s < 0) return;//到達可能なノードのみを通す
		if (dp[v][s] <= x) return;//あるノード、ある所持金で到達するまでの時間が既に小さい場合は通さない
		dp[v][s] = x;
		q.emplace(v, s, x);
	};
	push(0, s, 0);//初期位置の定義
	while (!q.empty()) {
		Node node = q.top(); q.pop();//時間が最小のnodeの取得
		int v = node.v, s = node.s;
		long long x = node.x;
		//if (dp[v][s] != x) continue;//??状態については2回以上遷移をさせたくないらしい。だが、なくても実行速度は変わらない
		{
			int ns = std::min(s + c[v], MAX_S);
			push(v, ns, x + d[v]);//銀貨を増やす場合を追加
		}
		//銀貨を増やさない場合の辺をたどる遷移
		for (Edge edge: g[v]) {//範囲ベースfor
	 	push(edge.to, s - edge.a, x + edge.b);
		}
	}

	for (int i = 1; i < n; i++) {
		long long ans = INF;
		for (int j = 0; j < MAX_S; j++) {
			ans = std::min(ans, dp[i][j]);
		}
		std::cout << ans << std::endl;
	}

}

#define rep(i,n) for (int i = 0; i < (n); ++i)
std::vector<int> s[2];
std::vector<unsigned long long> u[2];
const int N = 500;
int n;
int val[2][N];
int d[N][N];
std::vector<int> is, js;
unsigned long long ans[N][N];
using namespace std;

void flip() {
	rep(i, n)rep(j, i) {
		swap(d[i][j], d[j][i]);
	}
}

bool solve() {
	rep(i, n)rep(j, n) d[i][j] = -1;
	rep(k, 2) {
		rep(i, n) {
			int x = val[k][i];
			if (s[k][i] != x) {
				rep(j, n) {
					if (d[i][j] == !x) return false;
					d[i][j] = x;
				}
			}
		}
		flip();
	}
	rep(_, 2) {
		rep(k, 2) {
			rep(i, n) {
				int x = val[k][i];
				if (s[k][i] == x) {
					vector<int> p;
					bool ok = false;
					rep(j, n) {
						if (d[i][j] == -1) p.push_back(j);
						if (d[i][j] == x) ok = true;
					}
					if (ok) continue;
					if (p.size() == 0) return false;
					if (p.size() == 1) {
						d[i][p[0]] = x;
					}
				}
			}
			flip();
		}
	}

	vector<int> is, js;
	rep(i, n) {
		bool filled = true;
		rep(j, n) if (d[i][j] == -1) filled = false;
		if (!filled) is.push_back(i);
	}
	rep(j, n) {
		bool filled = true;
		rep(i, n) if (d[i][j] == -1) filled = false;
		if (!filled) js.push_back(j);
	}
	rep(i, is.size())rep(j, js.size()) {
		d[is[i]][js[j]] = (i + j) % 2;
	}
	return true;
}

using ull = unsigned long long;
void solve_F2() {
	cin >> n;
	rep(i, 2) {
		s[i] = vector<int>(n);
		rep(j, n) cin >> s[i][j];
	}
	rep(i, 2) {
		u[i] = vector<ull>(n);
		rep(j, n) cin >> u[i][j];
	}

	rep(b, 64) {
		rep(i, 2)rep(j, n) val[i][j] = u[i][j] >> b & 1;
		if (!solve()) {
			cout << "-1" << endl;
			return;
		}
		rep(i, n)rep(j, n) ans[i][j] |= ull(d[i][j]) << b;
	}
	rep(i, n) {
		rep(j, n) {
			cout << ans[i][j] << (j == n - 1 ? '\n' : ' ');
		}
	}
}


int main()
{
	//solve_A();
	//solve_B();
	//solve_C();
	//solve_D2();
	//solve_E();
	solve_F2();
    return 0;
}
