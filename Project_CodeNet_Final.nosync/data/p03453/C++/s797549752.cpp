#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define N_ 101000
#define pli pair<long long, int>
using namespace std;
int n, m;
vector<int>E[N_], L[N_];
int Q[N_], head, tail, Mod = 1000000007;
struct SP {
	int st, Deg[N_];
	long long D[N_], R[N_];
	vector<int>G[N_];
	priority_queue<pli>PQ;
	void Put(int a, long long d) {
		if (D[a] <= d)return;
		D[a] = d;
		PQ.push({ -d,a });
	}
	void Dijk(int a) {
		st = a;
		int i;
		for (i = 1; i <= n; i++)D[i] = 1e18;
		Put(st, 0);
		while (!PQ.empty()) {
			auto tp = PQ.top();
			PQ.pop();
			int x = tp.second;
			if (D[x] != -tp.first)continue;
			for (i = 0; i < E[x].size();i++) {
				Put(E[x][i], D[x] + L[x][i]);
			}
		}
	}
	void Do() {
		head = tail = 0;
		int i, x;
		R[st] = 1;
		for (i = 1; i <= n; i++)if (!Deg[i])Q[++tail] = i;
		while (head < tail) {
			x = Q[++head];
			for (auto &t : G[x]) {
				Deg[t]--;
				R[t] = (R[t] + R[x]) % Mod;
				if (!Deg[t])Q[++tail] = t;
			}
		}
	}
}P1, P2;
int R[N_];
long long Pow2(long long a) {
	a %= Mod;
	return a*a%Mod;
}
int main() {
	int i, j, a, b, c, S, T;
	scanf("%d%d", &n, &m);
	scanf("%d%d", &S, &T);
	for (i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		E[a].push_back(b);
		E[b].push_back(a);
		L[a].push_back(c);
		L[b].push_back(c);
	}
	P1.Dijk(S);
	P2.Dijk(T);
	for (i = 1; i <= n; i++) {
		for (j = 0; j < E[i].size(); j++) {
			int x = E[i][j];
			if (P1.D[i] + P2.D[x] + L[i][j] == P1.D[T]) {
				P1.G[i].push_back(x);
				P2.G[x].push_back(i);
				P1.Deg[x]++, P2.Deg[i]++;
			}
		}
	}
	P1.Do();
	P2.Do();
	int res = Pow2(P1.R[T]);
	for (i = 1; i <= n; i++) {
		if (P1.D[i] + P2.D[i] == P1.D[T] && P1.D[i] * 2 == P1.D[T]) {
			res = (res - Pow2(P1.R[i] * P2.R[i]) + Mod) % Mod;
		}
	}
	for (i = 1; i <= n; i++) {
		for (auto &tp : P1.G[i]) {
			if (P1.D[i] * 2 < P1.D[T] && P1.D[tp] * 2 > P1.D[T]) {
				res = (res - Pow2(P1.R[i] * P2.R[tp]) + Mod) % Mod;
			}
		}
	}
	printf("%d\n", res);
}