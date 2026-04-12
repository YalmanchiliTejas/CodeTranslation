#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <deque>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1000000007;
const int MAX_V = 201;
ll dp[2][4];
int now = 0;
int t[3];
ll p2[32];
bool use[100010];
int arr[256];
void Sequence() {
	int n;
	cin >> n;

	cout << (n * 800 - ((n / 15) * 200)) << endl;
}
int main() {
	Sequence();
	return 0;
}

