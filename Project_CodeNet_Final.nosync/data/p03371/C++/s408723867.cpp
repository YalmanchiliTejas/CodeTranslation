#include "bits/stdc++.h"
//#include <intrin.h>  //AtCoder (gcc) 上ではこれがあると動かない。__popcnt用のincludeファイル。
using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long
#define rep(i, n) for(long long i = 0; i < (n); i++)
#define sqrt(d) pow((long double) (d), 0.50)
#define PII pair<int, int>
#define MP make_pair

const int INF = 2000000000; //2e9
const long long INF2 = 1000000000000000000; //1e18
const long double pi = acos(-1);

const int MOD = 1000000007; //1e9 + 7
//const int MOD = 1000000009; //1e9 + 9
//const int MOD = 998244353;




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
	return dp.at(x) = (x * factorial2(x - 1, M, dp)) % M;
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




long long my_gcd(long long a, long long b) {
	if (b == 0) return a;
	return my_gcd(b, a % b);
}




// ax + by = gcd(a, b) を解く。返り値は、gcd(a, b)。
long long my_gcd_extended(long long a, long long b, long long& x, long long& y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}

	long long tempo = my_gcd_extended(b, a % b, y, x);

	//bx' + ry' = gcd(a, b) → (qb + r)x + by = gcd(a, b) に戻さないといけない。// (r = a % b)
	//b(x' - qy') + (bq + r)y' = gcd(a, b) と同値変形できるから、
	// x = y', y = x' - qy'
	y -= (a / b) * x;

	return tempo;
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
		long long denominator = 1;
		for (signed j = 0; j < n_digit - 1 - i; j++) {
			denominator *= base;
		}

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
	int n = dist.size();
	int m = dist.at(0).size();

	while (!que.empty()) {
		int h, w;
		pair<int, int> tempo = que.front(); que.pop();

		h = tempo.first;
		w = tempo.second;
		//cout << temp_i << " " << temp_j << endl;

		for (int dh = -1; dh <= 1; dh++) {
			for (int dw = -1; dw <= 1; dw++) {
				if (h + dh < 0 || n <= h + dh) continue;  //範囲外
				if (w + dw < 0 || m <= w + dw) continue;  //範囲外
				if (dh == 0 && dw == 0) continue; //動いていない
				if (dh * dw != 0) continue; //右上など。八近傍の場合は消す。
				if (dist.at(h + dh).at(w + dw) != -1) continue; //行けない領域に、既に INF などが代入されている場合はこの条件だけで ok

				dist.at(h + dh).at(w + dw) = dist.at(h).at(w) + 1;
				que.push(make_pair(h + dh, w + dw));
			}
		}

		//何か所も領域がある場合だけ必要
		if (que.empty()) {
			rep(i, n) {
				rep(j, m) {
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
	int n = dist.size();
	int m = dist.at(0).size();

	while (!que.empty()) {
		int h, w;
		pair<int, int> tempo = que.front(); que.pop_front();

		h = tempo.first;
		w = tempo.second;
		//cout << temp_i << " " << temp_j << endl;

		for (int dh = -1; dh <= 1; dh++) {
			for (int dw = -1; dw <= 1; dw++) {
				if (h + dh < 0 || n <= h + dh) continue;  //範囲外
				if (w + dw < 0 || m <= w + dw) continue;  //範囲外
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

const int Vmax2 = 1;
int dp_warshall[Vmax2][Vmax2];

//G.at(i).at(j) は i から j への移動コスト。隣接行列。
void warshall_floyd(int V, const vector<vector<int>> G) {
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

	UnionFind(int N) : parent(N), rank(N, 0) {
		rep(i, N) {
			parent.at(i) = i;
		}
	}

	int root(int x) {
		if (parent.at(x) == x) return x;
		return parent.at(x) = root(parent.at(x));
	}

	void unite(int x, int y) {
		int rx = root(x);
		int ry = root(y);

		if (rx == ry) return; //xの根とyの根が同じなので、何もしない。
		if (rank.at(rx) < rank.at(ry)) {
			parent.at(rx) = ry;
		}
		else {
			parent.at(ry) = rx;
			if (rank.at(rx) == rank.at(ry)) rank.at(rx)++;
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




class SegmentTree {
private:
	int ini = INF;

public:
	int Size;
	vector<int> node;

	SegmentTree(int N) : Size(N), node(N) {
		int new_N = 1;
		while (new_N < N) new_N *= 2;

		node.assign(2 * new_N - 1, ini);
		Size = new_N;
	}

	SegmentTree(vector<int> v) : Size(v.size()), node(v.size()) {
		int new_N = 1;
		while (new_N < (int)v.size()) new_N *= 2;

		node.assign(2 * new_N - 1, ini);
		Size = new_N;

		//葉の初期化
		for (int i = 0; i < (int)v.size(); i++) node.at(Size - 1 + i) = v.at(i);

		//上りながら初期化
		for (int i = Size - 2; i >= 0; i--) node.at(i) = min(node.at(2 * i + 1), node.at(2 * i + 2));
	}

	// k 番目の値 (0-indexed) を x に変更する。
	void update(int k, int x) {
		//葉のノードの番号 (等比数列の和の公式)
		k += Size - 1;
		node.at(k) = x;

		//上りながら更新 (0-indexedの場合、例えば、3 の子は、7, 8)
		while (k > 0) {
			k = (k - 1) / 2;

			//子の最小値を親の最小値とする。
			node.at(k) = min(node.at(k * 2 + 1), node.at(k * 2 + 2));
		}
	}

	//[a, b) の最小値を計算する。[l, r) は、ノード k に対応する区間を与える。
	//query(a, b, 0, 0, size) で呼べばよい。
	int query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return ini;  // 交差しない。
		if (a <= l && r <= b) return node.at(k); // 完全に含む。
		else {
			int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return min(vl, vr);
		}

	}
};




//転倒数を返す (comp = less<int>() の場合)。
//comp = greater<int>() の場合は、N_C_2 - 転倒数 を返すことになる。
int my_merge(vector<int>& A, vector<int>& B, int left, int mid, int right, function <bool(int, int)> comp) {
	int i = left; //Aを分割したときの、左側の配列を差す配列。
	int j = mid;  //Bを分割したときの、左側の配列を差す配列。
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




signed main() {
	
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	int res = 0;

	if (A + B <= 2 * C) {
		res = A * X + B * Y;
		cout << res << endl;
		return 0;
	}
	else if (2 * C <= min(A, B)) {
		res = 2 * C * max(X, Y);
		cout << res << endl;
		return 0;
	}
	else if (min(A, B) < 2 * C && 2 * C < max(A, B)) {
		if (A >= B) {
			swap(A, B); swap(X, Y);
		}
		//Bの方が高い。
		res += 2 * C * Y;
		res += A * max(0LL, X - Y);

		cout << res << endl;
		return 0;

	}
	else {
		res += 2 * C * min(X, Y);

		if (X >= Y) {
			res += A * (X - Y);
		}
		else {
			res += B * (Y - X);
		}

		cout << res << endl;
		return 0;
	}

}


