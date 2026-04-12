#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#define repp(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define repm(i,a,b) for(int i=(int)a;i>(int)b;--i)
using ll=long long;
static const ll mod = 1e9 + 7;
static const ll INF = 1LL << 50;
using namespace std;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int minv = a * x + b * y;
	minv = min(minv, c * 2 * max(x, y));
	int sel;
	if (x > y)sel = a;
	else sel = b;
	minv = min(minv, c * 2 * min(x, y) + sel * (max(x, y) - min(x, y)));
	cout << minv << endl;
	return 0;
}