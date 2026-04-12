#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <fstream>
#include <cassert>
using namespace std;
#pragma warning(disable : 4996)
typedef long long ll;



int main() {
#ifdef _DEBUG
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	cout << (n == m ? "Yes" : "No");
}