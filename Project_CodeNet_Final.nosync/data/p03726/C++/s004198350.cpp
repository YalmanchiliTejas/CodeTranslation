#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please

vector<int> E[100001];
int D[100001];
int kotae;
int dfs(int A) {
	if (D[A]) return 1;
	D[A] = 1;
	int goukei = 0;
	for (int i : E[A]) {
		goukei += dfs(i) ^ 1;
	}
	if (goukei > 1) kotae = 1;
	cesp(A);
	ce(goukei);
	return goukei;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;
	rep(i, N - 1) {
		int a, b;
		cin >> a >> b;
		E[a].pb(b);
		E[b].pb(a);
	}

	if (dfs(1) == 0) kotae = 1;

	if (kotae) co("First");
	else co("Second");

	Would you please return 0;
}