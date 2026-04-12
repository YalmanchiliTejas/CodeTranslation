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


ll L[51];
ll P[51];

ll keisan(ll A, ll B) {
	if (A == 0) return 1;
	if (L[A] == B) return P[A];

	ll kotae = 0;
	B--;

	if (B >= L[A - 1]) {
		kotae += P[A - 1];
		B -= L[A - 1];
	}
	else if (B > 0){
		kotae += keisan(A - 1, B);
		B = 0;
	}

	if (B > 0) {
		kotae++;
		B--;
	}

	if (B >= L[A - 1]) {
		kotae += P[A - 1];
		B -= L[A - 1];
	}
	else if (B > 0) {
		kotae += keisan(A - 1, B);
		B = 0;
	}

	return kotae;
}



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	ll N, X;
	cin >> N >> X;

	L[0] = 1;
	rep1(i, 50) {
		L[i] = 2 * L[i - 1] + 3;
	}
	P[0] = 1;
	rep1(i, 50) {
		P[i] = 2 * P[i - 1] + 1;
	}


	co(keisan(N, X));

	Would you please return 0;
}