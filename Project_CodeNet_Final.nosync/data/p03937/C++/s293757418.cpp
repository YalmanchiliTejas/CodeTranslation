#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)

//* 便利な変数
namespace {
	int dx4[] = { 1, -1, 0, 0 };
	int dy4[] = { 0, 0, 1, -1 };

	int dx8[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
	int dy8[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

	int mDays[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	ll A, B, C, D, E, F, G, H, I, J, K, L, M,
		N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

	const ll MOD_CONST = (ll)(1e9 + 7);
}
template <typename T>
vector<T> INP(ll n)
{
	vector<T> x;
	REP(i, n) {
		T tmp; cin >> tmp;
		x.push_back(tmp);
	}
	return move(x);
}
//* n文字1行の文字列を入力，一文字ごとの配列を返す
vector<char> SPRIT_STRING(ll n)
{
	string str; cin >> str;
	vector<char> cs(n);
	REP(i, n) cs[i] = str[i];
	return move(cs);
}
//* 文字列中から文字列を検索して別の文字列に置換する
void strReplace(std::string& str, const std::string& from, const std::string& to) {
	std::string::size_type pos = 0;
	while (pos = str.find(from, pos), pos != std::string::npos) {
		str.replace(pos, from.length(), to);
		pos += to.length();
	}
}
//* 素数関連関数
namespace PrimeLib {
	//* 素数判定 is_prime<unsigned>(N)
	template<typename T, std::enable_if_t<std::is_unsigned<T>::value, std::nullptr_t> = nullptr>
	bool is_prime(const T n) {
		if (n < 4) return n == 2 || n == 3;
		if (n % 2 == 0 || n % 3 == 0 || (n % 6 != 1 && n % 6 != 5)) return false;
		for (T i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false;
		return true;
	}
	//* 素数テーブル生成　エラトステネスの篩
	vector<ll> primeTable(ll n) {
		vector<bool> table(n - 1);
		vector<ll> ret;
		for (ll i = 0; i < n - 1; ++i) {
			if (table[i] == false) {
				ll num = i + 2;
				ret.push_back(i + 2);
				for (int j = i + num; j < n - 1; j += num)
					table[j] = true;	
			}
		}
		return ret;
	}
}
//* 組み合わせ計算
inline unsigned long long NChooseK(const unsigned long long& n, const unsigned long long& k)
{
	if (n  < k) return 0;
	if (0 == n) return 0;
	if (0 == k) return 1;
	if (n == k) return 1;
	if (1 == k) return n;
	typedef unsigned long long value_type;
	value_type* table = new value_type[static_cast<std::size_t>(n * n)];
	std::fill_n(table, n * n, 0);
	class n_choose_k_impl
	{
	public:

		n_choose_k_impl(value_type* table, const value_type& dimension)
			: table_(table),
			dimension_(dimension)
		{}

		inline value_type& lookup(const value_type& n, const value_type& k)
		{
			return table_[dimension_ * n + k];
		}

		inline value_type compute(const value_type& n, const value_type& k)
		{
			if ((0 == k) || (k == n))
				return 1;
			value_type v1 = lookup(n - 1, k - 1);
			if (0 == v1)
				v1 = lookup(n - 1, k - 1) = compute(n - 1, k - 1);
			value_type v2 = lookup(n - 1, k);
			if (0 == v2)
				v2 = lookup(n - 1, k) = compute(n - 1, k);
			return v1 + v2;
		}

		value_type* table_;
		value_type dimension_;
	};
	value_type result = n_choose_k_impl(table, n).compute(n, k);
	delete[] table;
	return result;
}
//* 座標nx, nyがWidth,Heightの領域内にあるかどうかのチェック
inline bool rangeCheck2D(int nx, int ny, int Width, int Height)
{
	return nx >= 0 and nx < Width and ny >= 0 and ny < Height;
}
//* bit全探索 
/*
	for (int i = 0; i < 1<<N; i++) {
		REP(j, N)
			if ((1 & i >> j) == 1) {;}
	}
*/
//* 値の二分探索
/*
	int lb = -1, ub = n;
	while (ub - lb > 1) {
		int mid = (lb + ub) / 2;
		if ( ) { // midが条件を満たす
			ub = mid; // 解の存在範囲は[lb, mid]
		} else {
			lb = mid; // 解の存在範囲は[mid, ub]
		}
	}
	int ans = ub;
*/
//* グラフのbfs 次のように格納
/*
struct edge { int to, cost; };
#define MAX_V 100
vector<edge> graph[MAX_V];
*/
//* 最短路
//* ベルマンフォード法　負の経路があっても動作
//* もし負の閉路があればfalseを返す
/*
struct edge {
	int from, to, cost;
};
bool bellmanFord(vector<edge>& es, vector<ll>& ds, int start) {
	for (auto& d : ds) d = INT64_MAX;
	ds[start] = 0;
	for (int n = 0; n < ds.size(); ++n) {
		for (int i = 0; i < es.size(); ++i) {
			edge e = es[i];
			if (ds[e.from] != INT64_MAX and
				ds[e.to] > ds[e.from] + e.cost) {
				ds[e.to] = ds[e.from] + e.cost;
				if (n == ds.size() - 1)
					return false;
			}
		}
	}
	return true;
}
*/
//* ワーシャル-フロイド法 全点対最短路　DPが基本 負の辺があってもOK(あると)
/*
const int MAX_V = 5;
ll cost[MAX_V][MAX_V];
int V;
void warshallFloyd()
{
	REP(k, V) {
		REP(i, V) {
			REP(j, V) {
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}
}
*/

namespace abc080d {
	void abc080d()
	{
		cin >> N >> C;
		typedef tuple<int, int, int> Show; // channel, start, end
		vector<Show> shows(N);
		REP(i, N) {
			int s, t, c;
			shows[i] = make_tuple(c, s, t);
		}
		sort(shows.begin(), shows.end());

	}
}

namespace agc015b {
	void agc015b()
	{
		string str; cin >> str;
		ll cnt = 0;
		REP(i, str.size()) {
			if (str[i] == 'U') {
				cnt += 2 * i;
				cnt += (str.size() - (i + 1));
			}
			else {
				cnt += i;
				cnt += 2 * (str.size() - (i + 1));
			}
		}
		cout << cnt << endl;
	}
}

namespace abc088d {
	void abc088d() {
		string str; cin >> str;
		int ans = INT32_MAX;
		REP(i, str.size()) {
			if (i == str.size() - 1) continue;
			if (str[i] == str[i + 1]) continue;
			int n = i + 1;
			ans = min(max(n, (int)str.size() - n), ans);
		}
		if (ans == INT32_MAX) {
			cout << str.size() << endl;
		}
		else
			cout << ans << endl;
	}
}

namespace abc089d {
	static char dp[2000][2000];
	bool isBlack(int dx, int dy, char c)
	{
		return c == dp[dx / K][dy / K];
	}
	void abc089d()
	{
		cin >> N >> K;
		REP(i, 2 * K) {
			REP(j, 2 * K) {
				bool bx = (i / K) % 2 == 0;
				bool by = (j / K) % 2 == 0;
				if (bx and by)
					dp[i][j] = 'W';
				else if (bx or by)
					dp[i][j] = 'B';
				else
					dp[i][j] = 'W';
			}
		}
		vector<pair<pair<int, int>, char>> xyc(N);
		REP(i, N) {
			cin >> xyc[i].first.first >> xyc[i].first.second >> xyc[i].second;
		}


		int ans = 0;
		REP(px, 2 *K) {
			REP(py, 2*K) {
				int cnt = 0;
				REP(i, N) {
					auto t = xyc[i];
					if (isBlack(px + t.first.first, py + t.first.second, t.second))
						cnt++;
				}
				ans = max(ans, cnt);
			}
		}
		cout << ans << endl;
	}
}

namespace abc051d {
	const int MAX_V = 101;
	ll cost[MAX_V][MAX_V];
	void warshallFloyd()
	{
		REP(k, N) {
			REP(i, N) {
				REP(j, N) {
					ll newCost = cost[i][k] + cost[k][j];
					if (cost[i][j] > newCost) {
						cost[i][j] = newCost;
					}
				}
			}
		}
	}
	void abc051d()
	{
		REP(i, N) {
			REP(j, N) {
				if (i == j) cost[i][j] = 0;
				else cost[i][j] = INT64_MAX;
			}
		}
		cin >> N >> M;
		vector<pair<pair<int, int>, int>> cs(M);
		REP(i, M) {
			int a, b, c; cin >> a >> b >> c;
			cost[a-1][b-1] = c;
			cost[b-1][a-1] = c;
			cs[i] = make_pair(make_pair(a-1, b-1), c);
		}
		warshallFloyd();

		int cnt = M;
		REP(m, M) {
			int a = cs[m].first.first, b = cs[m].first.second;
			bool del = false;
			REP(s, N) {
				if (cost[s][a] + cs[m].second == cost[s][b])
					del = true;
			}
			if (del) cnt--;
		}

		cout << cnt << endl;
	}
}

namespace abc087d {
	struct edge { int to, cost; };
	#define MAX_V 100001
	vector<edge> graph[MAX_V];
	bool visited[MAX_V];
	void abc087d()
	{
		set<int> exist;
		cin >> N >> M;
		REP(i, M) {
			int l, r, d; cin >> l >> r >> d;
			bool le = exist.find(l) != exist.end();
			bool re = exist.find(r) != exist.end();
			if (i == 0 or (not le and not re)) {
				exist.insert(l); exist.insert(r);
				graph[l].push_back(edge{ r, d });
				graph[r].push_back(edge{ l, -d });
			}
			else {
				if (not le) {
					exist.insert(l);
					graph[r].push_back(edge{ l, -d });
					graph[l].push_back(edge{ r, d });
				}
				else if (not re) {
					exist.insert(r);
					graph[l].push_back(edge{ r, d });
					graph[r].push_back(edge{ l, -d });
				}
				else {
					queue<pair<int, int>> rest; rest.push(make_pair(l, 0));
					REP(j, MAX_V) { visited[j] = false; }
					while (not rest.empty()) {
						int next = rest.front().first;
						int cost = rest.front().second;
						rest.pop();
						if (next == r) {
							if (cost == d) {
								break;
							}
							else {
								cout << "No" << endl;
								return;
							}
						}
						visited[next] = true;
						for (auto e : graph[next]) {
							if (visited[e.to]) continue;
							rest.push(make_pair(e.to, e.cost + cost));
						}
					}
				}
			}
		}
		cout << "Yes" << endl;
	}
}

namespace agc007a {
	void agc007a()
	{
		cin >> H >> W;
		int cnt = 0;
		REP(i, H) {
			string str; cin >> str;
			REP(j, W) {
				if (str[j] == '#') cnt++;
			}
		}
		if (cnt == H + W - 1)
			cout << "Possible" << endl;
		else
			cout << "Impossible" << endl;
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	//abc051d::abc051d();
	//arc078b::arc078b();
	agc007a::agc007a();
	return 0;
}
