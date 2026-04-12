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

//世界は天才だなぁ

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;
	int S[100000];
	rep(i, N) cin >> S[i];

	ll kotae = 0;
	rep1(ab, N / 2 - 1) {
		int n = ab;
		ll kari = 0;
		bool yoyuu = (N - 1) % n;
		while (n < N - 1 - ab && (yoyuu || n * 2 < N - 1)) {
			kari += S[n] + S[N - 1 - n];
			kotae = max(kotae, kari);
			n += ab;
		}
	}
	co(kotae);



	Would you please return 0;
}