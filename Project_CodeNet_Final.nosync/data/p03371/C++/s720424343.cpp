#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	int a, b, ab, numA, numB;
	cin >> a >> b >> ab >> numA >> numB;
	int s = a * numA + b * numB;
	int t = max(numA, numB) * ab * 2;
	int sw = (max(numA, numB) == numA) ? a: b;
	int u = 2 * ab * min(numA, numB) + sw * (max(numA, numB) - min(numA, numB));
	cout << min(min(s, t), u) << endl;
}

int main() {
	solve();
	return 0;
}