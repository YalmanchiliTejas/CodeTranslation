#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

class HistTree {
	typedef struct {
		cat h;
		int l, r, zero;
		vector<int> son;
	} node;

	constexpr static cat mod = 1000000007;

	int N;
	vector<cat> H;
	vector<node> T;

	void Build(int l, int r, cat h) {
		cat minh = H[l];
		for(int i = l; i < r; i++) minh = min(minh, H[i]);
		T.push_back({minh-h, l, r, 0, vector<int>()});
		int l_higher = r, id = T.size()-1;
		for(int i = l; i <= r; i++) {
			if(i < r && H[i] != minh) {
				if(l_higher == r) l_higher = i;
				continue;
			}
			if(i < r) T[id].zero++;
			if(l_higher == r) continue;
			T[id].son.push_back(T.size());
			Build(l_higher, i, minh);
			l_higher = r;
		}
	}

	cat pw(cat a, cat e) {
		if(e <= 0) return 1;
		cat x = pw(a, e/2);
		x = x * x % mod;
		if(e&1) x = x * a % mod;
		return x;
	}

public:
	HistTree(const vector<cat> & H) : N(H.size()), H(H) {
		Build(0, N, 0);
	}

	pair<cat, cat> Solve(int node_id = 0) {
		// returns: (all, with horizontally alternating bottom)
		node & n = T[node_id];
		vector< pair<cat, cat> > son_ans;
		ALL_THE(n.son, it) son_ans.push_back(Solve(*it));
		// vertically alternating
		cat cnt_valt = 1;
		ALL_THE(son_ans, it) cnt_valt = cnt_valt * (it->ff + 2 * it->ss) % mod;
		for(int i = 0; i < n.zero; i++) cnt_valt = cnt_valt * 2 % mod;
		// horizontally alternating
		pair<cat, cat> ret = {cnt_valt, 0};
		cat cnt_halt = 1;
		ALL_THE(son_ans, it) cnt_halt = cnt_halt * 2 * it->ss % mod;
		ret.ff = (ret.ff + (pw(2, n.h) - 2) * cnt_halt) % mod;
		if(ret.ff < 0) ret.ff += mod;
		ret.ss = cnt_halt * pw(2, n.h-1) % mod;
		return ret;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<cat> H(N);
	for(int i = 0; i < N; i++) cin >> H[i];
	HistTree T(H);
	cout << T.Solve().ff << "\n";
	return 0;
}

// look at my code
// my code is amazing
