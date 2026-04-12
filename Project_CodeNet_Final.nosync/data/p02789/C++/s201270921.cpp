#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define sort_unique(x) sort(ALL(x)); x.resize(distance(x.begin(), unique(ALL(x))))
#define MP make_pair
#define PB push_back
#define X first
#define Y second

typedef long long int lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(15);
    cout << fixed;

	int n, m;
	cin >> n >> m;

	if (n == m) {
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
	}
    
    return 0;
}