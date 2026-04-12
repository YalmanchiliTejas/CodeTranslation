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

int BIT[400011];

void add(int A, int B) {
	while (A <= 400010) {
		BIT[A] = max(BIT[A], B);
		A += A & -A;
	}
}

int query(int A) {
	int kotae = 0;
	while (A > 0) {
		kotae = max(BIT[A], kotae);
		A -= A & -A;
	}
	return kotae;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;
	int X[200000], Y[200000];
	vector<int> zenbu;
	int saidai = 0;
	int saishou = 1e9;
	int saidai2 = 0;
	int saishou2 = 1e9;
	rep(i, N) {
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		saidai = max(saidai, y);
		saidai2 = max(saidai2, x);
		saishou = min(saishou, x);
		saishou2 = min(saishou2, y);
		X[i] = x;
		Y[i] = y;
		zenbu.pb(x);
		zenbu.pb(y);
	}
	ll kotae1 = 1ll * (saidai - saishou2) * (saidai2 - saishou);

	sort(zenbu.begin(), zenbu.end());

	rep(i, N) {
		int x = lower_bound(zenbu.begin(), zenbu.end(), X[i]) - zenbu.begin() + 1;
		int y = lower_bound(zenbu.begin(), zenbu.end(), Y[i]) - zenbu.begin() + 1;
		add(1, x);
		add(x + 1, y);
	}

	int doko = lower_bound(zenbu.begin(), zenbu.end(), saishou2) - zenbu.begin() + 1;
	for (int i = 1; i <= doko; i++) {
		int k = query(i);
		ll kotae2 = 1ll * (saidai - saishou) * (zenbu[k - 1] - zenbu[i - 1]);
		kotae1 = min(kotae1, kotae2);
	}

	co(kotae1);

	Would you please return 0;
}