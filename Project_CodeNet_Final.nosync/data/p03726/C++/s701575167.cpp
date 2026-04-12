#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N; cin >> N;
		vector<vector<UL>> E(N);
		rep(i, N - 1) {
			UL a, b; cin >> a >> b; a--; b--;
			E[a].push_back(b);
			E[b].push_back(a);
		}
		vector<UL> F(N); rep(i, N) F[i] = E[i].size();
		//cout << "F = ";
		//rep(i, N) cout << F[i] << " "; cout << endl;
		vector<UL> A(N);
		queue<UL> Q; rep(i, N) if (F[i] == 1) Q.push(i);
		while (Q.size()) {
			UL p = Q.front(); Q.pop();
			if (A[p]) continue;
			UL nx = 0;
			for (UL e : E[p]) if (!A[e]) nx = e;
			//cout << "B = " << p << ", A = " << nx << endl;
			A[nx] = 1;
			for (UL e : E[nx]) {
				if (e == p) continue;
				if (A[e]) continue;
				F[e]--;
				//cout << "F[" << e << "] = " << F[e] << endl;
				if (F[e] == 0) { cout << "First" << endl; return; }
				if (F[e] == 1) { Q.push(e); }
			}
		}
		cout << "Second" << endl;
	}


	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}
