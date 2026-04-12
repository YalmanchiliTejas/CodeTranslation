#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int a, b, c;
	cin >> a >> b >> c;
	a -= b + c + c;
	int ans = 1;
	cout << ans + a / (b + c) << endl;
	return 0;
}

