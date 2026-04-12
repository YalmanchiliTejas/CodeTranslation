#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include "bits/stdc++.h"

#ifdef _MSC_VER
#include <intrin.h>  //gcc上ではこれがあると動かない。__popcnt, umul128 等用のincludeファイル。
#define __builtin_popcount __popcnt
#define __builtin_popcountll __popcnt64
//#pragma intrinsic(_umul128)
#endif

//#include <atcoder/all>
//using namespace atcoder;

//#include <boost/multiprecision/cpp_int.hpp>
//#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long
#define LL128 boost::multiprecision::int128_t
#define LL boost::multiprecision::cpp_int
#define LD100 boost::multiprecision::cpp_dec_float_100

#define rep(i, n) for(long long i = 0; i < (n); i++)
#define sqrt(d) pow((long double) (d), 0.50)
#define PII pair<int, int>
#define MP make_pair
#define PB push_back
#define ALL(v) v.begin(), v.end()

const int INF = std::numeric_limits<int>::max() / 2 - 100000000;
const long long INF2 = std::numeric_limits<long long>::max() / 2 - 100000000;
const long double pi = acos(-1);

constexpr int MOD = 1000000007; //1e9 + 7
//constexpr int MOD = 1000000009; //1e9 + 9
//constexpr int MOD = 998244353;




long long my_gcd(long long a, long long b) {
	if (b == 0) return a;
	return my_gcd(b, a % b);
}




// ax + by = gcd(a, b) を解く。返り値は、gcd(a, b)。
long long my_gcd_ext(long long a, long long b, long long& x, long long& y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}

	long long tempo = my_gcd_ext(b, a % b, y, x);

	//bx' + ry' = gcd(a, b) → (qb + r)x + by = gcd(a, b) に戻さないといけない。// (r = a % b)
	//b(x' - qy') + (bq + r)y' = gcd(a, b) と同値変形できるから、
	// x = y', y = x' - qy'
	y -= (a / b) * x;

	return tempo;
}




//M を法として、a の逆元を返す。但し gcd(a, M) = 1。
long long my_invmod(long long a, long long M) {
	long long x = 0, y = 0;
	long long memo = my_gcd_ext(a, M, x, y);
	assert(memo == 1LL);
	x %= M;
	if (x < 0) x += M;
	return x;
}




//繰り返し2乗法
//N^aの、Mで割った余りを求める。
ll my_pow(ll N, ll a, ll M) {
	ll tempo;
	if (a == 0) {
		return 1;
	}
	else {
		if (a % 2 == 0) {
			tempo = my_pow(N, a / 2, M);
			return (tempo * tempo) % M;
		}
		else {
			tempo = my_pow(N, a - 1, M);
			return (tempo * N) % M;
		}
	}
}

ll my_pow(ll N, ll a) {
	ll tempo;
	if (a == 0) {
		return 1;
	}
	else {
		if (a % 2 == 0) {
			tempo = my_pow(N, a / 2);
			return (tempo * tempo);
		}
		else {
			tempo = my_pow(N, a - 1);
			return (tempo * N);
		}
	}
}




//N_C_a を M で割った余り
ll my_combination(ll N, ll a, ll M) {
	if (N < a) return 0;

	ll answer = 1;

	rep(i, a) {
		answer *= (N - i);
		answer %= M;
	}

	rep(i, a) {
		answer *= my_pow(i + 1, M - 2, M);
		answer %= M;
	}

	return answer;
}


//N_C_i を M で割った余りを、v.at(i) に代入する。
void my_combination_table(ll N, ll M, vector<ll>& v) {
	v.assign(N + 1, 1);

	for (ll i = 1; i <= N; i++) {
		v.at(i) = v.at(i - 1) * (N - (i - 1LL));
		v.at(i) %= M;

		v.at(i) *= my_pow(i, M - 2, M);
		v.at(i) %= M;
	}
}


//(N + i)_C_N を M で割った余りを、v.at(i) に代入する。(v のサイズに依存)
void my_combination_table2(ll N, ll M, vector<ll>& v) {
	v.at(0) = 1;

	for (ll i = 1; i < (ll)v.size(); i++) {
		v.at(i) = v.at(i - 1) * (N + i);
		v.at(i) %= M;

		v.at(i) *= my_pow(i, M - 2, M);
		v.at(i) %= M;
	}
}




//階乗。x ! まで計算する。結果は dp に保存する。20 ! = 2.43e18 まで long long に入る。
ll factorial(ll x, vector<ll>& dp) {
	if ((ll)dp.size() <= x) {
		int n = dp.size();
		rep(i, x + 1 - n) {
			dp.push_back(0);
		}
	}

	if (x == 0) return dp.at(x) = 1;
	if (dp.at(x) != -1 && dp.at(x) != 0) return dp.at(x);
	return dp.at(x) = x * factorial(x - 1, dp);
}




//階乗の M で割った余り。x ! まで計算する。結果は dp に保存する。
ll factorial2(ll x, ll M, vector<ll>& dp) {
	if ((ll)dp.size() <= x) {
		int n = dp.size();
		rep(i, x + 1 - n) {
			dp.push_back(0);
		}
	}

	if (x == 0) return dp.at(x) = 1;
	if (dp.at(x) != -1 && dp.at(x) != 0) return dp.at(x);
	ll tempo = (x * factorial2(x - 1, M, dp));
	tempo %= M;
	return dp.at(x) = tempo;
}




//階乗の mod M での逆元 (M: prime)。x ! まで計算する。結果は dp に保存する。
ll factorial_inverse(ll x, ll M, vector<ll>& dp) {
	if ((ll)dp.size() <= x) {
		int n = dp.size();
		rep(i, x + 1 - n) {
			dp.push_back(0);
		}
	}

	if (x == 0) return dp.at(x) = 1;
	if (dp.at(x) != -1 && dp.at(x) != 0) return dp.at(x);
	return dp.at(x) = (my_pow(x, M - 2, M) * factorial_inverse(x - 1, M, dp)) % M;
}




//N_C_a を M で割った余り。何度も呼ぶ用。
ll my_combination2(ll N, ll a, ll M, vector<ll>& dp_factorial, vector<ll>& dp_factorial_inverse) {
	if ((ll)dp_factorial.size() <= N) {
		factorial2(N, M, dp_factorial);
	}
	if ((ll)dp_factorial_inverse.size() <= N) {
		factorial_inverse(N, M, dp_factorial_inverse);
	}

	if (N < a) return 0;

	ll answer = 1;
	answer *= dp_factorial.at(N);
	answer %= M;
	answer *= dp_factorial_inverse.at(N - a);
	answer %= M;
	answer *= dp_factorial_inverse.at(a);
	answer %= M;

	return answer;
}




// base を底としたときの、n の i桁目を、v.at(i) に入れる。(桁数は n に応じて自動で設定する。)
void ll_to_vector(signed base, long long n, vector<signed>& v) {
	long long tempo = n;
	long long tempo2 = n;

	signed n_digit = 1;
	while (tempo2 >= base) {
		tempo2 /= base;
		n_digit++;
	}

	v.assign(n_digit, 0);   // v のサイズを適切に調整する場合。

	// n_digit = v.size();  // v のサイズをそのままにする場合。

	for (signed i = 0; i < n_digit; i++) {
		long long denominator = my_pow(base, n_digit - 1 - i);

		v.at(i) = tempo / denominator;
		tempo -= v.at(i) * denominator;
	}
}




int char_to_int(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2; case '3': return 3; case '4': return 4;
	case '5': return 5; case '6': return 6; case '7': return 7; case '8': return 8; case '9': return 9;
	default: return 0;
	}
}




//エラトステネスの篩で、prime で ないところに false を入れる。O(n loglog n)
void prime_judge(vector<bool>& prime_or_not) {
	prime_or_not.assign(prime_or_not.size(), true);

	prime_or_not.at(0) = false;
	prime_or_not.at(1) = false;

	long long n = prime_or_not.size() - 1;

	for (long long i = 2; 2 * i <= n; i++) {
		prime_or_not.at(2 * i) = false;
	}


	for (long long i = 3; i * i <= n; i += 2) {
		//ここからは奇数のみ探索。i の倍数に false を入れる。
		if (prime_or_not.at(i)) {
			long long j = i * i;  // i^2 未満の i の倍数には、すでに false が入っているはず。
			while (j < n + 1) {
				prime_or_not.at(j) = false;
				j += 2 * i;
			}
		}
	}
};




// n + 1 の サイズの vector を返す。res.at(i) には、i の 1 以外で最小の約数を入れる。res.at(i) == i なら i は素数。
// 2e8 なら、3.2 秒程度で終わる。たぶん、prime_judge より 3倍弱遅い。
vector<long long> sieve(long long n) {
	n++; // n まで判定する。配列サイズは +1。

	vector<long long> res(n, 0);
	for (long long i = 1; i < n; i++) {
		if (i % 2 == 0) res.at(i) = 2;  // 偶数をあらかじめ処理。
		else res.at(i) = i;
	}

	for (long long i = 3; i * i < n; i += 2) {
		//ここからは奇数のみ探索。i の倍数に i を入れる。
		if (res.at(i) == i) {
			long long j = i * i;  // i^2 未満の i の倍数には、すでに最小の約数が入っているはず。
			while (j < n) {
				if (res.at(j) == j) res.at(j) = i;
				j += 2 * i;
			}
		}
	}

	return res;
};




//O (sqrt(n)) で素数判定する用。
bool is_prime(long long N) {
	if (N == 1 || N == 0) return false;
	if (N == 2 || N == 3) return true;

	if (N % 2 == 0) return false;
	if (N % 3 == 0) return false;

	for (long long i = 1; (6 * i + 1) * (6 * i + 1) <= N; ++i) {
		if (N % (6 * i + 1) == 0) return false;
	}
	for (long long i = 0; (6 * i + 5) * (6 * i + 5) <= N; ++i) {
		if (N % (6 * i + 5) == 0) return false;
	}
	return true;
}




//素因数分解を O(sqrt(N)) で行うための関数。
map<ll, ll> divide_to_prime(int target) {
	map<ll, ll> res;

	//sqrt(target) まで調べる。
	ll upper_lim = ceil(sqrt(target));
	vector<bool> prime_or_not(upper_lim + 3, true);
	if (upper_lim < 20) prime_or_not.assign(25, true);

	prime_or_not.at(0) = false; prime_or_not.at(1) = false;
	prime_judge(prime_or_not);

	ll tempo = target;
	for (int i = 1; i * i <= target; i++) {
		if (prime_or_not.at(i)) {
			while (tempo % i == 0) {
				tempo /= i;
				res[i]++;
			}
		}

		if (tempo == 1) break;  //別に必要はない。
	}

	if (tempo != 1) res[tempo]++; //sqrt(target) より大きな素因数は高々1つしかない。
	return res;
}




//関数 sieve で得た、vector min_factor を持ってるときに、素因数分解を高速で行うための関数。
map<long long, long long> divide_to_prime2(long long target, vector<long long>& min_factor) {
	map<long long, long long> res;
	if (min_factor.empty() || (long long)min_factor.size() - 1 < target) min_factor = sieve(target);

	while (target > 1) {
		res[min_factor[target]]++;
		target /= min_factor[target];
	}

	return res;
}




//約数全列挙を O(sqrt(N)) で行うための関数。
vector<long long> count_dividers(long long target) {

	vector <long long> dividers, tempo;
	long long i = 1;
	while (i * i < target + 1) {
		if (target % i == 0) {
			dividers.push_back(i);
			if (i < target / i) tempo.push_back(target / i);  // if節がないと、平方数の時、sqrt(target) がダブルカウントされる。
		}
		i++;
	}

	for (long long j = 0; j < (long long)tempo.size(); j++) {
		dividers.push_back(tempo.at(tempo.size() - 1 - j));
	}

	return dividers;
}




//関数 sieve で得た、vector min_factor を持ってるときに、約数全列挙を高速で行うための関数。
vector<long long> count_dividers2(long long target, vector<long long>& min_factor) {

	vector <long long> dividers = { 1 };
	map<long long, long long> memo = divide_to_prime2(target, min_factor);

	for (auto&& iter = memo.begin(); iter != memo.end(); iter++) {
		vector <long long> tempo = dividers;
		for (long long k = 0; k < (long long)tempo.size(); k++) {
			long long times = 1;
			for (long long j = 1; j <= (iter->second); j++) {
				times *= iter->first;
				dividers.push_back(tempo[k] * times);
			}
		}
	}

	sort(dividers.begin(), dividers.end());  //sortしないと小さい順に並ばないが、必要ないなら消しても良い。
	return dividers;
}




void BFS_labyrinth(queue<pair<int, int>>& que, vector<vector<int>>& dist, int& area) {
	int H = dist.size();
	int W = dist.at(0).size();

	while (!que.empty()) {
		int h, w;
		pair<int, int> tempo = que.front(); que.pop();

		h = tempo.first;
		w = tempo.second;
		//cout << temp_i << " " << temp_j << endl;

		for (int dh = -1; dh <= 1; dh++) {
			for (int dw = -1; dw <= 1; dw++) {
				if (h + dh < 0 || H <= h + dh) continue;  //範囲外
				if (w + dw < 0 || W <= w + dw) continue;  //範囲外
				if (dh == 0 && dw == 0) continue; //動いていない
				if (dh * dw != 0) continue; //右上など。八近傍の場合は消す。
				if (dist.at(h + dh).at(w + dw) != -1) continue; //行けない領域に、既に INF などが代入されている場合はこの条件だけで ok

				dist.at(h + dh).at(w + dw) = dist.at(h).at(w) + 1;
				que.push(make_pair(h + dh, w + dw));
			}
		}

		//何か所も領域がある場合だけ必要
		if (que.empty()) {
			rep(i, H) {
				rep(j, W) {
					if (dist.at(i).at(j) == -1) {
						que.push(make_pair(i, j));
						dist.at(i).at(j) = 0;
						area++;
						break;
					}
				}
				if (!que.empty()) break;
			}
		}
	}
}




void BFS01_labyrinth(deque<pair<int, int>>& que, vector<vector<int>>& dist, vector<vector<int>>& cost) {
	int H = dist.size();
	int W = dist.at(0).size();

	while (!que.empty()) {
		int h, w;
		pair<int, int> tempo = que.front(); que.pop_front();

		h = tempo.first;
		w = tempo.second;
		//cout << temp_i << " " << temp_j << endl;

		for (int dh = -1; dh <= 1; dh++) {
			for (int dw = -1; dw <= 1; dw++) {
				if (h + dh < 0 || H <= h + dh) continue;  //範囲外
				if (w + dw < 0 || W <= w + dw) continue;  //範囲外
				if (dh == 0 && dw == 0) continue; //動いていない
				if (dh * dw != 0) continue; //右上など。八近傍の場合は消す。
				if (dist.at(h + dh).at(w + dw) != -1) continue; //行けない領域に、既に INF などが代入されている場合はこの条件だけで ok

				dist.at(h + dh).at(w + dw) = dist.at(h).at(w) + cost.at(h + dh).at(w + dw);

				if (cost.at(h + dh).at(w + dw) == 0) {//コストが低い場合
					que.push_front(make_pair(h + dh, w + dw));
				}
				else {//コストが高い場合
					que.push_back(make_pair(h + dh, w + dw));
				}

			}
		}
	}
}




void dfs(const vector<vector<int>>& G, vector<bool>& seen, int v) {
	seen.at(v) = true;

	for (int next_v : G.at(v)) {
		if (seen.at(next_v)) continue;
		dfs(G, seen, next_v);
	}
}




class edge {
public:
	int to;
	int cost;
};

void dijkstra(int s, const vector<vector<edge>> G, vector<int>& dist) {
	int V = dist.size(); //頂点数
	dist.assign(V, INF);

	//first が最短距離、second が頂点番号。
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
	dist.at(s) = 0; que.push(make_pair(0, s));

	while (!que.empty()) {
		//cout << endl;
		//rep(i, H) {
			//rep(j, W) {
				//cout << dist.at(i * W + j) << " ";
			//}
			//cout << endl;
		//}
		//cout << endl;

		pair<int, int> p = que.top(); que.pop();
		int v = p.second;
		if (dist.at(v) < p.first) continue;  //最短距離がすでに更新されているので無視。

		for (int i = 0; i < (int)G.at(v).size(); i++) {
			edge e = G.at(v).at(i);
			//for (auto&& e : G.at(v)) {  // ← なぜか、やや遅いので。
			if (dist.at(e.to) > dist.at(v) + e.cost) {
				dist.at(e.to) = dist.at(v) + e.cost;
				que.push(make_pair(dist.at(e.to), e.to));
			}
		}
	}
}




class Edge {
public:
	int from;
	int to;
	int cost;
};

vector<int> BellmanFord(const int s, vector<int>& dist, vector<Edge> G) {
	const int V = dist.size();
	vector<int> res; //負閉路内の点を入れる。

	//初期化
	dist.assign(V, INF);
	dist.at(s) = 0;

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < (int)G.size(); j++) {
			Edge e = G.at(j);

			if (dist[e.to] > dist[e.from] + e.cost) {  //移動した後のコストが小さいと、頂点のコストを更新
				dist[e.to] = dist[e.from] + e.cost;
				if (i == V - 1) {         //頂点の数と同じ回数ループすると、負の閉路があるのでループをぬける
					res.push_back(e.to);
					//return true;
				}
			}
		}
	}

	return res;
	//return false;
}




const int Vmax2 = 1;
int dp_warshall[Vmax2][Vmax2];

//G.at(i).at(j) は i から j への移動コスト。隣接行列。
void warshall_floyd(const int V, const vector<vector<int>> G) {
	rep(i, V) {
		rep(j, V) {
			dp_warshall[i][j] = G.at(i).at(j);  //初期化
		}
	}

	rep(k, V) {
		rep(i, V) {
			rep(j, V) {
				dp_warshall[i][j] = min(dp_warshall[i][j], dp_warshall[i][k] + dp_warshall[k][j]);
			}
		}
	}
}




class UnionFind {
public:
	vector<int> parent;
	vector<int> rank;
	vector<int> v_size;

	UnionFind(int N) : parent(N), rank(N, 0), v_size(N, 1) {
		rep(i, N) {
			parent[i] = i;
		}
	}

	int root(int x) {
		if (parent[x] == x) return x;
		return parent[x] = root(parent[x]); //経路圧縮
	}

	void unite(int x, int y) {
		int rx = root(x);
		int ry = root(y);

		if (rx == ry) return; //xの根とyの根が同じなので、何もしない。
		if (rank[rx] < rank[ry]) {
			parent[rx] = ry;
			v_size[ry] += v_size[rx];
		}
		else {
			parent[ry] = rx;
			v_size[rx] += v_size[ry];
			if (rank[rx] == rank[ry]) rank[rx]++;
		}
	}

	bool same(int x, int y) {
		return (root(x) == root(y));
	}

	int count_tree() {
		int N = parent.size();
		int res = 0;

		rep(i, N) {
			if (root(i) == i) res++;
		}

		return res;
	}

	int size(int x) {
		return v_size[root(x)];
	}
};




class wUnionFind {
public:
	vector<int> parent;
	vector<int> diff_weight; //親との差分。
	vector<int> rank;

	wUnionFind(int N) : parent(N), diff_weight(N, 0), rank(N, 0) {
		rep(i, N) {
			parent.at(i) = i;
		}
	}

	int root(int x) {
		if (parent.at(x) == x) return x;

		int r = root(parent.at(x));
		diff_weight.at(x) += diff_weight.at(parent.at(x)); //累積和
		return parent.at(x) = r;
	}

	//x の重みを出力する関数。
	int weight(int x) {
		root(x);
		return diff_weight.at(x);
	}

	//weight.at(y) - weight.at(x) == w となるようにする。
	bool unite(int x, int y, int w) {
		int rx = root(x);
		int ry = root(y);
		int diff_weight_to_ry_from_rx = w + weight(x) - weight(y);

		if (rx == ry) return false; //xの根とyの根が同じなので、何もしない。
		if (rank.at(rx) < rank.at(ry)) {
			parent.at(rx) = ry;
			diff_weight.at(rx) = -diff_weight_to_ry_from_rx;
		}
		else {
			parent.at(ry) = rx;
			diff_weight.at(ry) = diff_weight_to_ry_from_rx;
			if (rank.at(rx) == rank.at(ry)) rank.at(rx)++;
		}

		return true;
	}

	bool same(int x, int y) {
		return (root(x) == root(y));
	}

	int count_tree() {
		int N = parent.size();
		int res = 0;

		rep(i, N) {
			if (root(i) == i) res++;
		}

		return res;
	}
};




//転倒数を返す (comp = less_equal<int>() の場合)。
//comp = greater<int>() の場合は、N_C_2 - 転倒数 を返すことになる。
int my_merge(vector<int>& A, vector<int>& B, int left, int mid, int right, function <bool(int, int)> comp) {
	int i = left; //Aを分割したときの、左側の配列を差す添え字。
	int j = mid;  //Aを分割したときの、右側の配列を差す添え字。
	int k = 0;  //分割した後の配列 (一時的に) B に保存。

	int res = 0;

	while (i < mid && j < right) {
		if (comp(A.at(i), A.at(j))) B.at(k++) = A.at(i++);
		else {
			B.at(k++) = A.at(j++);
			res += mid - i;
		}
	}

	//左側をBに移動し尽くしたので、右側を順に入れていく。
	if (i == mid) {
		while (j < right) {
			B.at(k++) = A.at(j++);
		}
	}
	else { //右側をBに移動し尽くしたので、左側を順に入れていく。
		while (i < mid) {
			B.at(k++) = A.at(i++);
		}
	}

	//Aに値を戻す。
	rep(l, k) {
		A.at(left + l) = B.at(l);
	}

	return res;
}


int my_merge_sort(vector<int>& target, vector<int>& tempo, int left, int right, function <bool(int, int)> comp) {

	int mid, res = 0;
	if (left == right || left == right - 1) return res;

	mid = (left + right) / 2;
	res += my_merge_sort(target, tempo, left, mid, comp);
	res += my_merge_sort(target, tempo, mid, right, comp);
	res += my_merge(target, tempo, left, mid, right, comp);
	return res;
}


int my_merge_sort(vector<int>& target, vector<int>& tempo, int left, int right) {
	return my_merge_sort(target, tempo, left, right, less_equal<int>());
}




// 幾何。二点間距離。
ld calc_dist(int x1, int x2, int y1, int y2) {
	int tempo = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	ld res = sqrt((ld)tempo);
	return res;
}




//next[i][v] → 頂点 v の 2^i 先。
//next.at(i).at(j) = next.at(i - 1).at(next.at(i - 1).at(j));
int doubling(vector<vector<int>> next, int v, int N) {
	vector<signed> memo;
	ll_to_vector(2, N, memo);

	int M = 0;
	M = memo.size();  //上と下のどちらか。上の方が計算量的には有利。
	//M = next.size();

	int now = v;
	for (int i = 0; i < M; i++) {
		if (N & (int)(1LL << i)) {
			now = next.at(i).at(now);
			//cout << (int)(1LL << i) << endl;
		}
	}

	return now;
}




//ラングレス圧縮
vector<pair<int, char>> compress(string S) {
	int N = S.size();
	vector<pair<int, char>> memo;

	int tempo = 1;
	for (int i = 1; i < N; i++) {
		if (i != N - 1) {
			if (S.at(i) == S.at(i - 1)) tempo++;
			else {
				memo.push_back(MP(tempo, S.at(i - 1)));
				tempo = 1;
			}
		}
		else {
			if (S.at(i) == S.at(i - 1)) {
				tempo++;
				memo.push_back(MP(tempo, S.at(i - 1)));
			}
			else {
				memo.push_back(MP(tempo, S.at(i - 1)));
				memo.push_back(MP(1, S.at(i)));
			}
		}
	}

	return memo;
}




//1-indexed
template<typename T>
class BIT {
public:
	vector<T> data;
	vector<T> bit;
	int N;

	//n は対象の配列 v の要素数
	BIT(int n, T ini) : data(n + 1, ini), bit(n + 1, ini), N(n + 1) {};
	BIT(int n) : data(n + 1, 0), bit(n + 1, 0), N(n + 1) {};

	//data[a] += w;
	void add(int a, T w) {
		data[a] += w;
		for (int x = a; x < N; x += x & -x) bit[x] += w;
	}


	//data[1] + … + data[a]
	T sum(int a) {
		T res = 0;
		for (int x = a; x > 0; x -= x & -x) res += bit[x];
		return res;
	}


	//半開区間 [l, r) の和
	T sum(int l, int r) {
		if (l == 0 || l == 1) return sum(r - 1);
		else return sum(r - 1) - sum(l - 1);
	}


	//data[1] + … + data[x] >= w なる最小の x (ただし、dataは全て正)
	int lower_bound(T w) {
		if (w <= (T)0) return 0;

		int x = 0, r = 1;
		while (r * 2 < N) r *= 2; // r は N 以下の最小の 2冪
		for (int len = r; len > 0; len /= 2) {// 長さlenは1段下るごとに半分に
			if (x + len < N && bit[x + len] < w) {
				// 採用するとき
				w -= bit[x + len];
				x += len;
			}
		}
		return x + 1;
	}

};




//1-indexed
template<typename T>
class BIT_imos {
public:
	vector<T> data;
	vector<T> data2;
	vector<T> bit;
	vector<T> bit2;
	int N;

	//n は対象の配列 v の要素数
	BIT_imos(int n, T ini) : data(n + 1, ini), data2(n + 1, ini), bit(n + 1, ini), bit2(n + 1, ini), N(n + 1) {};
	BIT_imos(int n) : data(n + 1, 0), data2(n + 1, 0), bit(n + 1, 0), bit2(n + 1, 0), N(n + 1) {};

	//[l, r) に += w;
	void add(int l, int r, T w) {
		data[l] += w;
		data2[l] += -w * (l - 1);
		if (r < N) {
			data[r] += -w;
			data2[r] += w * (r - 1);
		}

		for (int x = l; x < N; x += x & -x) bit[x] += w;
		for (int x = l; x < N; x += x & -x) bit2[x] += -w * (l - 1);

		if (r < N) {
			for (int x = r; x < N; x += x & -x) bit[x] += -w;
			for (int x = r; x < N; x += x & -x) bit2[x] += w * (r - 1);
		}

	}


	//data[1] + … + data[a]
	T sum(int a) {
		T res = 0;
		for (int x = a; x > 0; x -= x & -x) res += a * bit[x];
		for (int x = a; x > 0; x -= x & -x) res += bit2[x];
		return res;
	}


	//半開区間 [l, r) の和
	T sum(int l, int r) {
		if (l == 0 || l == 1) return sum(r - 1);
		else return sum(r - 1) - sum(l - 1);
	}
};




void printf_ld(ld res) {
	printf("%.12Lf\n", res);
	//cout << std::fixed << std::setprecision(12) << res << endl;
}




//Ford-Fulkerson algorithm
template<class Cap>
class MaxFlow {
public:
	//コンストラクタ
	MaxFlow() : N(0) {}
	MaxFlow(int n) : N(n), G(n) {}



	//from から to への 容量 cap の辺を追加する。
	//0-indexed で、何番目に追加された辺かを返す。
	int add_edge(int from, int to, Cap cap) {
		assert(0 <= from && from < N);
		assert(0 <= to && to < N);
		assert(0 <= cap);
		int m = (int)(pos.size());
		pos.push_back({ from, (int)(G[from].size()) });
		G[from].push_back(edge1{ to, (int)(G[to].size()), cap });
		G[to].push_back(edge1{ from, (int)(G[from].size()) - 1, 0 });
		return m;
	}



	struct edge1 {
		int to;  //行先
		int rev; //逆辺
		Cap cap; //容量
	};



	struct edge2 {
		int from;
		int to;  //行先
		Cap cap; //容量
		Cap flow; //流量
	};



	//i番目に追加された辺を返す。
	edge2 get_edge(int i) {
		int m = (int)(pos.size());
		assert(0 <= i && i < m);

		auto _e = G[pos[i].first][pos[i].second];
		auto _rev = G[_e.to][_e.rev];
		return edge2{ pos[i].first, _e.to, _e.cap + _rev.cap, _rev.cap };
	}
	//全ての辺を入れたvectorを返す。
	std::vector<edge2> edges() {
		int m = (int)(pos.size());
		std::vector<edge2> res;
		for (int i = 0; i < m; i++) {
			res.push_back(get_edge(i));
		}
		return res;
	}
	//i番目の辺の容量、流量の変更
	void change_edge(int i, Cap new_cap, Cap new_flow) {
		int m = (int)(pos.size());
		assert(0 <= i && i < m);
		assert(0 <= new_flow && new_flow <= new_cap);
		auto& _e = G[pos[i].first][pos[i].second];
		auto& _rev = G[_e.to][_e.rev];
		_e.cap = new_cap - new_flow;
		_rev.cap = new_flow;
	}



	//flow(s, t)を1回呼んだ後に呼ぶと、s, t間の最小カットを返す。
	std::vector<bool> min_cut(int s) {
		std::vector<bool> seen(N);
		queue<int> que;
		que.push(s);
		while (!que.empty()) {
			int v = que.front(); que.pop();
			seen[v] = true;
			for (auto e : G[v]) {
				if (e.cap && !seen[e.to]) {
					seen[e.to] = true;
					que.push(e.to);
				}
			}
		}
		return seen;
	}



	//増加パスをDFSで探す
	Cap dfs(int v, const int t, Cap flow, vector<bool>& seen) {
		if (v == t) return flow;
		seen[v] = true;

		for (int i = 0; i < (int)(G[v].size()); i++) {
			edge1& e = G[v][i];
			if (seen[e.to] || e.cap <= 0) continue;
			int res = dfs(e.to, t, min(flow, e.cap), seen);

			if (res > 0) {
				e.cap -= res;
				G[e.to][e.rev].cap += res;
				return res;
			}
		}
		return 0;
	};



	Cap flow(int s, int t) {
		assert(0 <= s && s < N);
		assert(0 <= t && t < N);

		Cap res = 0;
		while (true) {
			vector<bool> seen(N, false);
			Cap flow = dfs(s, t, inf, seen);
			if (flow == 0) return res;
			res += flow;
		}
	}



private:
	int N;

	//i番目の辺を保存する。{from_i, G[from_i] の何番目の要素か}
	std::vector<std::pair<int, int>> pos;
	std::vector<std::vector<edge1>> G;

	const Cap inf = std::numeric_limits<Cap>::max() - 3;
};




signed main() {
	int N, X, M;
	cin >> N >> X >> M;

	if (X == 0) {
		cout << 0 << endl;
		return 0;
	}
	if (X == 1) {
		int res = N;
		cout << res << endl;
		return 0;
	}

	vector<int> A;
	int sum = 0;

	map<int, int> memo;
	map<int, int> memo2;

	int s = -1;
	int T = -1;

	rep(i, N) {
		if (i == 0) {
			A.push_back(X % M);
		}
		else {
			A.push_back((A.back() * A.back()) % M);
		}

		sum += A.back();
		memo[A.back()]++;
		if (memo[A.back()] == 1) memo2[A.back()] = i;
		else {
			s = memo2[A.back()];
			T = i - s;
			break;
		}
	}


	if (s == -1) {
		cout << sum << endl;
		return 0;
	}

	int res = 0;
	int sum1 = 0;
	rep(i, s) {
		res += A.at(i);
	}
	N -= s;

	for (int i = s; i < s + T; i++) {
		sum1 += A.at(i);
	}

	res += sum1 * (N / T);
	N %= T;

	for (int i = s; i < s + N; i++) {
		res += A.at(i);
	}

	cout << res << endl;
}
