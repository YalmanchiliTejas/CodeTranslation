#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	string S; cin >> S;
	for (int i = 0; i < S.length() - 1;i++) {
		if (S[i] == 'A' && S[i + 1] == 'C') {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}