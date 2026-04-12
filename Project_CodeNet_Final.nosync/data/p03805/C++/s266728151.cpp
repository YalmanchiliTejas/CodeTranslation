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

int N, M;
vector<int> E[9];
int kotae;

void sagasu(int A, int B) {
	if ((B >> A & 1) == 0) {
		B += 1 << A;
		for (auto itr : E[A]) {
			sagasu(itr, B);
		}

		if (B == ((1 << N + 1) - 2)) kotae++;
	}
	
}



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	
	cin >> N >> M;

	rep(i, M) {
		int a, b;
		cin >> a >> b;
		E[a].pb(b);
		E[b].pb(a);
	}

	sagasu(1, 0);

	co(kotae);

	Would you please return 0;
}