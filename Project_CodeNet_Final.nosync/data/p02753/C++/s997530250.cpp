#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define ALL(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
const ll INF = ll(1e15)+10;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;

int main() {
	string S;
	cin >> S;
	int numA = 0;
	int numB = 0;
	rep(i, S.size()) {
		if (S[i] == 'A') numA++;
		if (S[i] == 'B') numB++;
	}
	if (numA > 0 && numB > 0) cout << "Yes";
	else cout << "No";
	cout << endl;
	return 0;
}
