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
ll x, y;
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
vector <long long>vl[100005];
vector <long long>llv[30005];
vector <long long>vll;
vector <long long>v;
vector <pl>vpl;
vector <string> vs;
set<ll> llset;
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


	UnionFind(ll Amount) : pairent(Amount, 1), depth(Amount, 1), size(Amount, 0) {

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




ll GCD(int a, int b) {
	if (a % b == 0)return b;
	else return GCD(b, a % b);
}

ll Min(ll a,ll b) {
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

bool gone[200002] = {};

void DFS(ll num ,ll count) {
	count++;
	gone[num] = true;
	for (ll i = 0; i < vl[num].size(); i++) {
		if (gone[vl[num][i]] == false) {
			gone[vl[num][i]] = true;
			DFS(vl[num][i],count);
		}
	}

	D[num] = count;

}

void DFS2(ll num, ll count) {
	count++;
	gone[num] = true;
	for (ll i = 0; i < vl[num].size(); i++) {
		if (gone[vl[num][i]] == false) {
			gone[vl[num][i]] = true;
			DFS2(vl[num][i], count);
		}
	}

	E[num] = count;

}

ll conb(ll n, ll k, ll mod) {
	ll a = C[n];
	a *= D[k];
	a %= mod;
	a *= D[n - k];
	a %= modd;
	return a;
}




int main() {

	cin >>SS;

	lp(i, SS.size()) {
		A[SS[i] - 'A']++;
	}

	if (A[0] > 0 && A[1] > 0)cout << "Yes" << endl;
	else cout << "No" << endl;

	//cout << fixed << setpql.ecision(10) << ansa << endl;
	return 0;

}
