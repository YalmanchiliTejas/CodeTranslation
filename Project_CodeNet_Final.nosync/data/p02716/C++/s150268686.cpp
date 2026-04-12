//#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <sstream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <numeric>
#include <bitset>
#include <iomanip>
#include <cctype>
#include <cstdlib>      // srand,rand
#include <random>
#include <functional>

using namespace std;
#define ll long long
#define lp(i,n) for(ll i=0;i<n;i++)

#define modd 1000000007
#define mod2 998244353

#define INF 8223372036854775807ll
#define ALL(a)  (a).begin(),(a).end()


typedef pair<long long, long long> pl;
typedef pair<double, double> pd;
typedef pair<ll, string> pls;



typedef string::const_iterator State;
class ParseError {};



/*
class SegmentTree {



private:

	ll cont_num = 2;
	pd initial_v;
	vector<pd> dat;


public:


	SegmentTree() {};


	void init(ll size, double initial_value_first, double initial_value_second) {

		cont_num = 2;
		initial_v.first = initial_value_first;
		initial_v.second = initial_value_second;

		while (cont_num < size) {
			cont_num *= 2;
		}

		dat.resize(2 * cont_num);//サイズ設定

		for (int i = 0; i < 2 * cont_num; i++)dat[i] = initial_v;//初期化



	}


	void Update(ll position, double value_f, double value_s) {



		ll k = cont_num + position;

		dat[k].first = value_f;
		dat[k].second = value_s;

		while (k > 1) {
			k /= 2;
			dat[k].first = dat[k * 2 + 1].first * dat[k * 2].first;
			dat[k].second = dat[k * 2 + 1].first * dat[k * 2].second + dat[k * 2 + 1].second;


		}


	}

	/*
	ll query_proces(ll a, ll b, ll k, ll l, ll r) {

		if (r <= a || b <= l)return initial_v;

		if (a <= l && r <= b)return dat[k];
		else {
			ll vl = query_proces(a, b, k * 2, l, (l + r) / 2);
			ll vr = query_proces(a, b, k * 2 + 1, (l + r) / 2, r);
			return min(vl, vr);
		}

	}


	ll query(ll left, ll right) {
		return query_proces(left, right, 1, 0, cont_num);
	}
	*/
	/*
		double query() {
			return dat[1].first + dat[1].second;
		}

	};*/


template <typename T>
class Zip {
	vector<T> d;
	bool flag;
	void init() {
		sort(d.begin(), d.end());
		d.erase(unique(d.begin(), d.end()), d.end());
		flag = false;
	}
public:
	Zip() {
		flag = false;
	}
	void add(T x) {
		d.push_back(x);
		flag = true;
	}
	ll getNum(T x) {
		if (flag) init();
		return lower_bound(d.begin(), d.end(), x) - d.begin();
	}
	ll size() {
		if (flag) init();
		return (ll)d.size();
	}
};


ll N, M, K, a, b, c, d, e, H, W, L, T;
ll x, y, z;
ll A[2000004] = {};
ll B[2000004] = {};
ll C[2000004] = {};
ll D[1000006] = {};
ll E[1000006] = {};
bool f;
string S[200000];
string SS;
set <long long>sll;
pl bufpl;
vector <long long>vl[100002];
vector <long long>llv[30005];
vector <long long>vll;
vector <long long>v;
vector <pl>vpl;
vector <string> vs;
set<ll> llset;
set<string> Sset;
multiset<ll> llmset;
queue<ll> ql;
multiset<pl> plmset;


typedef struct ST
{
	ll first;
	ll second;
	ll cost;

	bool operator<(const ST& another) const
	{
		return first < another.first;//比較
	};

	bool operator>(const ST& another) const
	{
		return first > another.first;//比較
	};

}ST;
//queue<ST> qst;
priority_queue<ST, vector<ST>, greater<ST> > qst;
multiset<ST> stmset;
ST bufst;
ST stt[100000];


/*vector <ST> vst;
ST st[200005];
ST bufst;
bitset<5000> bits;*/


long long modinv(long long aa, long long mm) {
	long long bb = mm, uu = 1, vv = 0;
	while (bb) {
		long long tt = aa / bb;
		aa -= tt * bb; swap(aa, bb);
		uu -= tt * vv; swap(uu, vv);
	}
	uu %= mm;
	if (uu < 0) uu += mm;
	return uu;
}





ll zettai(ll aa) {

	if (aa < 0) {
		aa *= -1;
	}
	return aa;

}

float zettai(float aa) {

	if (aa < 0) {
		aa *= -1;
	}
	return aa;

}


/*
class UnionFind
{

public:


	vector <ll>pairent;
	vector <ll>depth;
	vector <ll>size;


	UnionFind(ll Amount) : pairent(Amount, 1), depth(Amount, 1), size(Amount, 1) {

		for (ll i = 0; i < Amount; i++) {
			pairent[i] = i;
		}


	}


	ll FindPairent(ll x) {
		if (pairent[x] == x)return x;
		else return pairent[x] = FindPairent(pairent[x]);

	}


	ll Merge(ll x, ll y) {
		x = FindPairent(x);
		y = FindPairent(y);

		if (x != y) {
			if (depth[x] > depth[y]) {
				pairent[y] = pairent[x];
				return size[x] += size[y];
			}
			else {
				pairent[x] = pairent[y];
				if (depth[x] == depth[y]) {
					depth[y] ++;
				}

				return size[y] += size[x];
			}

		}
		else {
			return -1;
		}



	}



	bool IsSame(ll x, ll y) {
		if (FindPairent(x) == FindPairent(y))return true;
		else return false;
	}


	ll GetSize(ll x) {
		x = FindPairent(x);
		return size[x];
	}


};
*/

class UnionFind
{

public:


	vector <ll>pairent;
	vector <ll>depth;
	vector <ll>size;


	UnionFind(ll Amount) : pairent(Amount, 1), depth(Amount, 1), size(Amount, 1) {

		for (ll i = 0; i < Amount; i++) {
			pairent[i] = i;
		}


	}


	ll FindPairent(ll x) {
		if (pairent[x] == x)return x;
		else return pairent[x] = FindPairent(pairent[x]);

	}


	ll Merge(ll x, ll y) {
		x = FindPairent(x);
		y = FindPairent(y);

		if (x != y) {
			if (depth[x] > depth[y]) {
				pairent[y] = pairent[x];
				return size[x] += size[y];
			}
			else {
				pairent[x] = pairent[y];
				if (depth[x] == depth[y]) {
					depth[y] ++;
				}

				return size[y] += size[x];
			}

		}
		else {
			return -1;
		}



	}



	bool IsSame(ll x, ll y) {
		if (FindPairent(x) == FindPairent(y))return true;
		else return false;
	}


	ll GetSize(ll x) {
		x = FindPairent(x);
		return size[x];
	}


};

class Nibutan {

public:
	ll hidari = 0;
	ll migi = 0;
	ll abc;
	vector<ll> contents;

	bool Jouken(int ser) {

		if (contents[ser] > abc) {
			return true;
		}
		else {
			return false;
		}

	}

	void Settings(int amount, ll terget) {
		migi = amount - 1;
		abc = terget;
	}


	ll tansaku() {

		hidari = -1;
		migi = contents.size();
		ll jud;

		while (hidari != migi - 1) {
			jud = hidari + migi;
			jud /= 2;
			if (Jouken(jud)) {
				migi = jud;
			}
			else {
				hidari = jud;
			}

		}

		return hidari;

	}


};



ll RepeatSquaring(ll N, ll P, ll M) {
	if (P == 0) return 1;
	if (P % 2 == 0) {
		ll t = RepeatSquaring(N, P / 2, M) % M;
		return t * t % M;
	}
	return N * RepeatSquaring(N, P - 1, M) % M;
}

/*
ll KurikaesiNijou(ll a, ll b, ll P) {

	if (b == 0)return 1;
	if (b % 2 == 0) {
		ll c=KurikaesiNijou(a,b/2,P)%P;
		return c * c %P;
	}
	else {
		ll c = KurikaesiNijou(a, b/2, P) % P;
		return a * c * c % P;
	}

}*/




ll GCD(ll a, ll b) {
	if (a % b == 0)return b;
	else return GCD(b, a % b);
}

ll Min(ll a, ll b) {
	if (a < b)return a;
	else return b;
}

ll Max(ll a, ll b) {
	if (a > b)return a;
	else return b;
}

ll Sum(ll a, ll b) {
	return a + b;
}

template <typename T>
class SegmentTree {
	ll n;
	vector<T> node;
	function<T(T, T)> fun, fun2;
	bool customChange;
	T outValue, initValue;
public:
	void init(ll num, function<T(T, T)> resultFunction, T init, T out, function<T(T, T)> changeFunction = NULL) {
		// changeFunction: (input, beforevalue) => newvalue
		fun = resultFunction;
		fun2 = changeFunction;
		customChange = changeFunction != NULL;
		n = 1;
		while (n < num) n *= 2;
		node.resize(2 * n - 1);
		fill(node.begin(), node.end(), init);
		outValue = out;
		initValue = init;
	}
	void valueChange(ll num, T value) {
		num += n - 1;
		if (customChange) node[num] = fun2(value, node[num]);
		else node[num] = value;
		while (num > 0) num = (num - 1) / 2, node[num] = fun(node[num * 2 + 1], node[num * 2 + 2]);
	}
	T rangeQuery(ll a, ll b, ll l = 0, ll r = -1, ll k = 0) { // [a, b)
		if (r == -1) r = n;
		if (a <= l && r <= b) return node[k];
		if (b <= l || r <= a) return outValue;
		ll mid = (l + r) / 2;
		return fun(rangeQuery(a, b, l, mid, 2 * k + 1), rangeQuery(a, b, mid, r, 2 * k + 2));
	}
};




class Combination {

	vector<ll> factorial;
	vector<ll> factorial_inv;
	ll mod;
	ll max_n;


public:
	void Init(ll init_max_n, ll init_mod) {
		max_n = init_max_n;
		mod = init_mod;
		factorial.resize(max_n + 1);
		factorial[0] = 1;
		for (ll i = 1; i < factorial.size(); i++) {
			factorial[i] = factorial[i - 1] * i;
			factorial[i] %= mod;
		}

		factorial_inv.resize(max_n + 1);
		factorial_inv[0] = 1;
		for (ll i = 1; i < factorial_inv.size(); i++) {
			factorial_inv[i] = factorial_inv[i - 1] * modinv(i, mod);
			factorial_inv[i] %= mod;
		}
	}



	ll GetComb(ll n, ll k) {
		ll comb = factorial[n];
		comb *= factorial_inv[k];
		comb %= mod;
		comb *= factorial_inv[n - k];
		comb %= mod;
		return comb;
	}

};



class Tree {

	ll node_N;
	vector<ll> node;
	vector<vector<pl>> pass;
	ll diameter = -1;
	vector<ll> dist_Diamieter[2];

	pl maxDist_Num;

public:


	void Init(ll node_Num) {
		node_N = node_Num;
		node.resize(node_N + 1);
		pass.resize(node_N + 1);

		dist_Diamieter[0].resize(node_N + 1);
		lp(i, node_N + 1)dist_Diamieter[0][i] = -1;
		dist_Diamieter[1].resize(node_N + 1);
		lp(i, node_N + 1)dist_Diamieter[1][i] = -1;
	}

	void AddEdge(ll a, ll b, ll dist) {
		bufpl.first = b;
		bufpl.second = dist;
		pass[a].push_back(bufpl);
		bufpl.first = a;
		pass[b].push_back(bufpl);
	}


	void DFS(ll step, ll now, ll dist) {

		dist_Diamieter[step][now] = dist;
		if (dist_Diamieter[step][now] > maxDist_Num.first) {
			maxDist_Num.first = dist_Diamieter[step][now];
			maxDist_Num.second = now;
		}

		for (ll i = 0; i < pass[now].size(); i++) {
			ll next_node = pass[now][i].first;
			if (dist_Diamieter[step][next_node] == -1) {
				DFS(step, next_node, dist + pass[now][i].second);
			}
		}
	}

	ll GetDiameter(ll min_node_num) {
		if (diameter >= 0)return diameter;
		else {
			maxDist_Num.first = -1;
			maxDist_Num.second = -1;
			DFS(0, min_node_num, 0ll);
			ll step2_start = maxDist_Num.second;

			maxDist_Num.first = -1;
			maxDist_Num.second = -1;
			DFS(1, step2_start, 0ll);

			diameter = maxDist_Num.first;
			return diameter;
		}
	}

	ll GetDistFromMinNode(ll num) {
		return dist_Diamieter[0][num];
	}

};


void Nibu(ll node, ll co) {

	C[node] = co % 2;
	D[co % 2]++;

	lp(i, vl[node].size()) {
		ll next = vl[node][i];
		if (C[next] == -1) {
			Nibu(next, co + 1);
		}
	}

}

Combination combi;
SegmentTree<ll> st;

bool gone[200005];
pl ko_to[200005];
/*
pl DFS(ll n) {

	pl buf;
	buf.first = 1;
	buf.second = 1;
	gone[n] = true;

	lp(i, vl[n].size()) {
		if (gone[vl[n][i]] == false) {
			bufpl = DFS(vl[n][i]);
			buf.first += bufpl.first;
			buf.second *= bufpl.second;
			buf.first %= modd;
			buf.second %= modd;
			vl[n].push_back(bufpl.first);
		}
	}

	buf.second *= C[buf.first - 1];
	buf.second %= modd;
	lp(i, vl[n].size()) {
		buf.second *= D[vl[n][i]];
		buf.second %= modd;
	}

	ko_to[n] = buf;
	return buf;

}*/


ll dp[200005][5];

int main() {


	cin >> N;

	lp(i, N) {
		cin >> A[i + 1];
	}

	lp(i, N + 1) {
		lp(j, 5) {
			dp[i][j] = INF - 2;
			dp[i][j] *= -1;
		}
	}

	for (ll i = 1; i <= N; i++) {
		if (i == 1) {
			dp[1][0] = A[i];
			dp[1][1] = 0;
		}
		else if (i == 2) {
			dp[2][0] = A[i];
			dp[2][1] = 0;
		}
		else {

			if (i >= 2) {
				lp(j, 4) {
					dp[i][j + 1] = max(dp[i][j + 1], dp[i - 2][j]);
				}

				lp(j, 5) {
					dp[i][j] = max(dp[i][j], dp[i - 2][j] + A[i]);
				}

			}

			if (i >= 3) {

				if (i % 2 == 1) {

					lp(j, 3) {
						dp[i][j + 2] = max(dp[i][j + 2], dp[i - 3][j]);
					}

					lp(j, 4) {
						dp[i][j + 1] = max(dp[i][j + 1], dp[i - 3][j] + A[i]);
					}
				}
				else {

					lp(j, 4) {
						dp[i][j + 1] = max(dp[i][j + 1], dp[i - 3][j]);
					}

					lp(j, 5) {
						dp[i][j] = max(dp[i][j], dp[i - 3][j] + A[i]);
					}

				}

			}

			if (i >= 4) {


				lp(j, 3) {
					dp[i][j + 2] = max(dp[i][j + 2], dp[i - 4][j]);
				}

				lp(j, 4) {
					dp[i][j + 1] = max(dp[i][j + 1], dp[i - 4][j] + A[i]);
				}

			}

		}

	}


	ll ans = 0;
	if (N % 2 == 0) {
		ans = max(dp[N][0], dp[N - 1][0]);
	}
	else {
		ans = max(dp[N][1], dp[N - 1][0]);
		ans = max(ans, dp[N - 2][0]);
	}

	cout << ans << endl;


	//cout << fixed << setprecision(12) << ansa << endl;
	return 0;

}
