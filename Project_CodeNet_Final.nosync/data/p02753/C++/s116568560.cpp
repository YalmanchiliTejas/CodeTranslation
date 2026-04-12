#pragma GCC optimize("O2,Ofast,inline,unroll-all-loops,-ffast-math")
#include <bits/stdc++.h>
#define pb(X) push_back(X)
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9 + 7;
int q;

int main() {
	INIT
	string s;
	cin >> s;
	if (s == "AAA" || s == "BBB") {
		cout <<"No\n";
	} else {
		cout <<"Yes\n";
	}

	return 0;
}