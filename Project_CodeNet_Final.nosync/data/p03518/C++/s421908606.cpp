#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
using namespace std;

#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1, T2> P)
{
	return s << '<' << P.first << ", " << P.second << '>';
}
template<class T> ostream& operator << (ostream &s, vector<T> P)
{
	for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s;
}
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{
	for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl;
}
template<class T1, class T2> ostream& operator << (ostream &s, map<T1, T2> P)
{
	EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl;
}




int N;
int p[210];

vector<int> res;



typedef int VAL;
const int MAX_B = 300;

int SIZE_B;
struct BIT {
	VAL dat[MAX_B + 1];

	void init(int n = 1) {
		SIZE_B = n;
		for (int i = 0; i <= SIZE_B; ++i) dat[i] = 0;
	}

	inline void add(int a, VAL x) {
		for (int i = a; i <= SIZE_B; i += i & -i)
			dat[i] = dat[i] + x;
	}

	inline VAL sum(int a) {
		VAL res = 0;
		for (int i = a; i > 0; i -= i & -i)
			res = res + dat[i];
		return res;
	}

	inline VAL sum(int a, int b) {
		return sum(b - 1) - sum(a - 1);
	}

	void print() {
		for (int i = 1; i <= SIZE_B; ++i) cout << sum(i, i + 1) << ",";
		cout << endl;
	}
};

BIT bit;

int calc() {
	int res = 0;
	bit.init(N + 2);
	int start = 0;
	for (start = 0; start < N; ++start) if (p[start] == 0) break;
	for (int i = start; i < start + N; ++i) {
		int tmp = bit.sum(p[i % N] + 1, N + 3);
		res += tmp;
		bit.add(p[i % N] + 1, 1);
	}
	return res;
}

void jun(int k) {
	for (int i = k; i < N; ++i) swap(p[i], p[i - k]);
}

void inv(int k) {
	for (int i = N - 1; i >= k; --i) swap(p[i], p[i - k]);
}


// a, a-1
void swapp(int a) {
	for (int i = 0; i < a; ++i) res.push_back(1);
	res.push_back(N - 1);
	for (int i = 0; i < N - a; ++i) res.push_back(1);
	swap(p[a], p[a - 1]);
}


void last() {
	int start = 0;
	for (start = 0; start < N; ++start) if (p[start] == 0) break;
	for (int i = 0; i < start; ++i) res.push_back(1);
}


void solve2() {
	/*
	for (int i = 0; i < N - 1; ++i) {
		for (int j = N - 1; j > i; --j) {
			if (p[j - 1] > p[j]) {
				swapp(j);
			}
		}
	}
	*/

	while (true) {
		int tento = calc();
		if (tento == 0) {
			last();
			break;
		}

		while (p[0] == 0 || p[N-1] == 0 || p[0] >= p[N-1]) {
			res.push_back(1);
			jun(1);
		}

		res.push_back(N - 1);
		jun(N - 1);
	}
}


void solve() {
	for (int iter = 0; iter < 10000; ++iter) {
		int cur_tento = calc();
		int Min_tento = 1 << 29;
		int mk1 = -1, mk2 = -1, mk3 = -1;
		for (int k1 = 1; k1 <= N - 1; ++k1) {
					jun(k1);
					int tmp_tento = calc();
					if (chmin(Min_tento, tmp_tento)) {
						mk1 = k1;
					}
					inv(k1);
		}

		
		/*
		cout << "---------------" << endl << "iter " << iter << endl << "p = ";
		for (int i = 0; i < N; ++i) {
			cout << p[i] << ", ";
		}
		cout << endl;
		COUT(cur_tento);
		COUT(mk1);
		COUT(mk2);
		COUT(mk3);
		COUT(Min_tento);
		*/

		if (Min_tento < cur_tento) {
			res.push_back(mk1);
			jun(mk1);
			//jun(mk2);
			//jun(mk3);
		}
		else {
			solve2();
			break;
		}
	}
}

int q[210];

int main() {
	while (cin >> N) {
		for (int i = 0; i < N; ++i) cin >> p[i], q[i] = p[i];
		res.clear();
		solve();
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); ++i) {
			cout << res[i] << endl;
		}


		for (int i = 0; i < res.size(); ++i) {
			int k = res[i];
			for (int i = k; i < N; ++i) swap(q[i], q[i - k]);
		}

		
		//for (int i = 0; i < N; ++i) cout << q[i] << ", "; cout << endl;
	
	}
}


