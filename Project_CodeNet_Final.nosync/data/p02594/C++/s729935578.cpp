//
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define lch (o << 1)
#define rch (o << 1 | 1)

typedef double db;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> pint;
typedef tuple<int, int, int> tint;

const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;

int main() {
	ios::sync_with_stdio(0);

	int x;
	cin >> x;
	int f = x >= 30;
	cout << (f ? "Yes" : "No") << endl;

	return 0;
}
