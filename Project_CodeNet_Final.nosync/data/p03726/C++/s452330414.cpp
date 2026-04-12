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


pair<int, int> E[200002];
int H[100001];
bool D[100001];
bool kotae;
bool dfs(int A) {
	if (D[A]) return 0;
	D[A] = true;
	int goukei = 0;
	for (int i = H[A]; i; i = E[i].second) {
		goukei += dfs(E[i].first);
	}
	if (goukei > 1) kotae = true;
	return goukei ^ 1;
}

const int cm = 1 << 17;
char cn[cm], * ci = cn + cm, ct;
inline char getcha() {
	if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }
	return *ci++;
}
inline int getint() {
	int A = 0;
	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';
	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
	return A;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N = getint();
	for (int i = 1; i < N + N - 2; i += 2) {
		int a = getint(), b = getint();
		
		E[i] = mp(b, H[a]);
		H[a] = i;
		E[i + 1] = mp(a, H[b]);
		H[b] = i + 1;
	}

	if (dfs(1)) kotae = true;

	if (kotae) co("First");
	else co("Second");

	Would you please return 0;
}