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
	string S[50];
	rep(i, N) cin >> S[i];

	int A[26][50] = {};

	rep(i, N) {
		rep(ii, S[i].size()) {
			A[S[i][ii] - 'a'][i]++;
		}
	}

	string kotae;
	rep(i, 26) {
		int kari = *min_element(A[i], A[i] + N);
		rep(ii, kari) kotae += (char)('a' + i);
	}
	co(kotae);

	Would you please return 0;
}