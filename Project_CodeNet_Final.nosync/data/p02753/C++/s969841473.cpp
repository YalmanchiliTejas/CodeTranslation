#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;
ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string S;
	cin >> S;
	sort(begin(S), end(S));
	S.erase(unique(begin(S), end(S)), end(S));
	if (S.size() == 1) cout << "No" << endl;
	else cout << "Yes" << endl;
}