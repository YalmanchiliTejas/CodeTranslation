#include"bits/stdc++.h"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;

template <typename T>
bool chmax(T& a, const T& b) {
	if (a < b) {
		a = b;  // aをbで更新
		return true;
	}
	return false;
}

template <typename T>
bool chmin(T& a, const T& b) {
	if (a > b) {
		a = b;  // aをbで更新
		return true;
	}
	return false;
}


int main() {
	string bus;
	cin >> bus;
	bool a = false, b=false;
	for (auto s : bus) {
		if (s == 'A')a = true;
		if (s == 'B')b = true;
	}

	if (a && b)cout << " Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
