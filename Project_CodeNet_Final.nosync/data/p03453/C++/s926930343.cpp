//ProblemE

#ifdef _MYPC
#include "mypc.h"
#endif // _MYPC

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <memory>
#include <cstdio>
#include <cstring>

#define _MOD 1000000007
#define MAXN 100000
#define MAXM 200000
#define NOTSET 0x7FFFFFFFFFFFFFFFL

using namespace std;

//ProblemE

template<int MOD = _MOD>
class ModInt {
public:
	ModInt(int val = 0) : val(val) {
		if (val < 0) (val %= MOD) += MOD;
	}
	ModInt(long long val) : val(val %= MOD) {
		if (val < 0) val += MOD;
	}
	operator int() const { return val; }
	ModInt& operator+= (const ModInt& b) {
		val = (val + b.val) % MOD;
		return *this;
	}
	ModInt& operator-= (const ModInt& b) {
		val = (val - b.val + MOD) % MOD;
		return *this;
	}
	ModInt& operator*= (const ModInt& b) {
		val = ((long long)(val) * b.val) % MOD;
		return *this;
	}
	ModInt operator+ (const ModInt& b) const { return val + b.val; }
	ModInt operator- (const ModInt& b) const { return val - b.val; }
	ModInt operator* (const ModInt& b) const { return (long long)val * b.val; }
private:
	int val;
};


class Solve {
private:
	int n, m;
	int s, t;

	using MInt = ModInt<>;
	struct Edge {
		int to;
		long long time;
	};
	vector<Edge> edges[MAXM];

	struct {
		MInt cnt = 0;
		long long time = NOTSET;
	} FS[MAXN], FT[MAXN];

	bool flags[MAXN];

	void MinPath(decltype(FS) &F, int beg, int end) {
		set<int, std::function<bool(const int&, const int&)>> pq([&F](const int &a, const int &b) {
			if(F[a].time == F[b].time) return a < b;
			else return F[a].time < F[b].time;
		});

		F[beg] = { 1, 0 };
		for(int i = 0;i < n; i++) pq.insert(i);

		while (!pq.empty()) {
			int top = *pq.begin();
			pq.erase(pq.begin());

			for (auto& e : edges[top]) {
				if (F[top].time + e.time < F[e.to].time) {
					pq.erase(e.to);
					F[e.to] = { F[top].cnt, F[top].time + e.time };
					pq.insert(e.to);
				}
				else if (F[top].time + e.time == F[e.to].time) {
					F[e.to].cnt += F[top].cnt;
				}
			}
		}
	}

	void solve() {
		cin >> n >> m;
		cin >> s >> t;
		s--; t--;

		for (int i = 0; i < m; i++) {
			int l, r, d;
			cin >> l >> r >> d;
			l--; r--;
			edges[l].push_back({ r, d });
			edges[r].push_back({ l, d });
		}

		MinPath(FS, s, t);
		MinPath(FT, t, s);

		auto minTime = FS[t].time;
		if (FS[t].time != FT[s].time)
			throw;

		MInt total = FS[t].cnt * FT[s].cnt;

		if (minTime % 2 == 0) {
			for (int i = 0; i < n; i++) {
				if (minTime / 2 == FS[i].time) {
					total -= FS[i].cnt * FS[i].cnt * FT[i].cnt * FT[i].cnt;
				}
			}
		}

		for (int i = 0; i < n; i++) for (auto e : edges[i]) {
			if (FS[i].time * 2 < minTime && FS[e.to].time * 2 > minTime
				&& FS[i].time + e.time + FT[e.to].time == minTime) {
				total -= FS[i].cnt * FS[i].cnt * FT[e.to].cnt * FT[e.to].cnt;
			}
		}

		cout << total << endl;
	}

public:
	Solve() { solve(); }
};

int main(int argc, char* argv[]) {
	unique_ptr<Solve> solve = make_unique<Solve>();
	return 0;
}
