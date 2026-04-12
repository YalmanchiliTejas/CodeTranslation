#include <bits/stdc++.h>
#define INF 2147483647
#define INF_LL 9223372036854775807
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	int r, g, b;
	cin >> r >> g >> b;
	if ((100 * r + 10 * g + b) % 4 == 0)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}