#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <string>
#define endl '\n'
#define ll long long

using namespace std;

int main(void)
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int r, g, b; cin >> r >> g >> b;
	int ret = r * 100 + g * 10 + b;
	if (ret % 4 == 0)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}