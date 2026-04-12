#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
typedef long long ll;

int main()
{
	int r, g, b;
	cin >> r >> g >> b;
	if ((g * 10 + b) % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
