#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx = 1e5 + 7;
const int Inf = 1 << 30;
const ll INF = 1ll << 60;
#define mst(x) memset(x, 0, sizeof(x))
priority_queue <int> qua;
int x;

int main() {
	cin >> x;
	if(x == 3 || x == 5 || x == 7) puts("YES");
	else puts("NO");
}