#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
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
using namespace std;
void GridCompression() {
	int H, W;
	cin >> H >> W;
	char a[101][101];
	bool h[101],w[101];
	//memset(h, false, sizeof(h));
	//memset(w, false, sizeof(w));

	for (size_t i = 0; i < H; i++)
	{
		for (size_t j = 0; j < W; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == '#') {
				h[i] = true;
				w[j] = true;
			}
		}
	}

	for (size_t i = 0; i < H; i++)
	{
		if (!h[i]) continue;
		for (size_t j = 0;  j < W;  j++)
		{
			if (!w[j]) continue;
			cout << a[i][j];
		}
		cout << "\n";
	}
}

int main() {
	GridCompression();
	return 0;
}