#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	static const ULL MOD = 1000000007;

	void Solve() {
		UL N, M; cin >> N >> M;
		UL s, t; cin >> s >> t; s--; t--;
		vector<vector<pair<UL, ULL>>> E(N);
		rep(i, M) {
			UL u, v; cin >> u >> v; u--; v--;
			ULL d; cin >> d;
			E[u].push_back({ v, d });
			E[v].push_back({ u, d });
		}
		ULL ans, sub; ans = sub = 0;
		vector<ULL> DS, DT;
		vector<ULL> PS, PT;
		DS.assign(N, -1); DT.assign(N, -1);
		PS.assign(N, 0); PT.assign(N, 0);
		PS[s] = 1; PT[t] = 1;
		using Node = pair<pair<ULL, UL>, UL>;
		priority_queue<Node, vector<Node>, greater<Node>> Q;
		Q.push({ { 0, s }, (UL)-1 });
		while (Q.size()) {
			ULL d = Q.top().first.first; UL p = Q.top().first.second;
			UL pre = Q.top().second;
			Q.pop();
			if (DS[p] != -1) {
				if (DS[p] == d) PS[p] = (PS[p] + PS[pre]) % MOD;
				continue;
			}
			DS[p] = d;
			if (pre != -1) PS[p] = (PS[p] + PS[pre]) % MOD;
			for (auto e : E[p]) {
				Q.push({ { d + e.second, e.first }, p });
			}
		}
		Q.push({ { 0, t }, (UL)-1 });
		while (Q.size()) {
			ULL d = Q.top().first.first; UL p = Q.top().first.second;
			UL pre = Q.top().second;
			Q.pop();
			if (DT[p] != -1) {
				if (DT[p] == d) PT[p] = (PT[p] + PT[pre]) % MOD;
				continue;
			}
			DT[p] = d;
			if (pre != -1) PT[p] = (PT[p] + PT[pre]) % MOD;
			for (auto e : E[p]) {
				Q.push({ { d + e.second, e.first }, p });
			}
		}
		ans = PS[t] * PT[s] % MOD;
		//cout << ans << endl;

		ULL D = DS[t];
		//cout << "D = " << D << endl;
		//cout << "DS = "; rep(i, N) cout << DS[i] << " "; cout << endl;
		//cout << "DT = "; rep(i, N) cout << DT[i] << " "; cout << endl;
		//cout << "PS = "; rep(i, N) cout << PS[i] << " "; cout << endl;
		//cout << "PT = "; rep(i, N) cout << PT[i] << " "; cout << endl;

		rep(p, N) {
			for (auto e : E[p]) {
				if (DS[p] + DT[e.first] + e.second == D) {
					if (DS[p] * 2 < D) {
						if (DS[e.first] * 2 > D) {
							ULL tmp = PS[p] * PT[e.first] % MOD;
							tmp = tmp * tmp % MOD;
							//cout << p << " " << e.first << " " << tmp << endl;
							sub = (sub + tmp) % MOD;
						}
					}
				}
			}
			if (DS[p] * 2 == D) {
				ULL tmp = PS[p] * PT[p] % MOD;
				tmp = tmp * tmp % MOD;
				//cout << p << " " << tmp << endl;
				sub = (sub + tmp) % MOD;
			}
		}

		ans = (ans + MOD - sub) % MOD;
		cout << ans << endl;
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
