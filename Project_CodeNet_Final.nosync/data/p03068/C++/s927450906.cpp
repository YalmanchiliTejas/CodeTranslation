#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string S;
	cin >> S;
	int k;
	cin >> k;

	rep(i, n) {
		if (S[i] != S[k - 1]) S[i] = '*';
	}

	dunk(S);

	return 0;
}