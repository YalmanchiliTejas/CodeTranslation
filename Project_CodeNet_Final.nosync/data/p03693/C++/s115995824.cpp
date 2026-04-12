#include <bits/stdc++.h>
using namespace std;

#define pb         push_back

typedef long long ll;
const ll INF = 1000000000000000000ll;
const ll MOD = 1000000007ll;
const double EPS = 1e-8;

int main(void) {
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	
	int r, g, b;
	cin >> r >> g >> b;

	if((100*r + 10*g + b) % 4 == 0) puts("YES");
	else puts("NO");
	
	return 0;
}
