#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1e9;
int main() {
	int X;
	cin >> X;
	bool can = false;
	if (X == 3 || X == 5 || X == 7)can = true;
	if (can)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}