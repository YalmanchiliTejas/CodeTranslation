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


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;

	ll X[200000], Y[200000];
	ll saishou = 1e9;
	ll saidai = 0;
	ll saishouY = 1e9;
	ll saidaiX = 0;
	rep(i, N) {
		cin >> X[i] >> Y[i];
		if (X[i] > Y[i]) swap(X[i], Y[i]);
		saishou = min(saishou, X[i]);
		saidai = max(saidai, Y[i]);
		saishouY = min(saishouY, Y[i]);
		saidaiX = max(saidaiX, X[i]);
	}

	ll kotae = (saidai - saishouY) * (saidaiX - saishou);

	ll ue = saidaiX;
	ll sita = 1e9;
	kotae = min(kotae, (ue - saishou) * (saidai - saishou));

	vector<pair<ll, ll>> V;
	rep(i, N) {
		V.pb(mp(X[i], Y[i]));
	}
	sort(V.begin(), V.end());

	rep(i, N) {
		kotae = min(kotae, (ue - min(sita, V[i].first)) * (saidai - saishou));
		sita = min(sita, V[i].second);
		ue = max(ue, V[i].second);
	}
	kotae = min(kotae, (ue - sita) * (saidai - saishou));

	co(kotae);

	Would you please return 0;
}