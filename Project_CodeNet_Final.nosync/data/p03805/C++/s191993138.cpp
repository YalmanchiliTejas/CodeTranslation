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
typedef long long ll;
using namespace std;

const int INF = 10e8;
int table[9][9];
bool used[9];
int n;
int count(int v,int c) {

	if (c == n) {
		return 1;
	}
	int res = 0;
	for (size_t i = 1; i <= n; i++)
	{
		if (!used[i] && table[v][i] == 1) {
			used[i] = true;
			res += count(i, c + 1);
			used[i] = false;
		}
	}
	return res;
}
void OnestrokePath(){
	int m;
	cin >> n >> m;
	for (size_t i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		table[a][b] = 1;
		table[b][a] = 1;
	}
	used[1] = true;
	cout << count(1, 1) << endl;
}

int main() {
	OnestrokePath();
	return 0;
}

