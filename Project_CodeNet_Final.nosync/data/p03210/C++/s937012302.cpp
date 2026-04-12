#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>

using namespace std;

int n, m;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	if (n == 3 || n == 5 || n == 7)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}