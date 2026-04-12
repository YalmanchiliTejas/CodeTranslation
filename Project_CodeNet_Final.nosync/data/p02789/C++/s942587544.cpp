// USACO_2020_1_a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
//#include <bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
#define endl "\n"
struct el { string word; int x, y, dir; };
int n, m, k, cnt, i, j, a = 0, b = 0, used[100][100], minx=1e9, miny=1e9, maxx=0, maxy=0, cntminx, cntmaxx, cntminy, cntmaxy;
	char c[100][100];
	void dfs(int x, int y)
	{
		if (x < 0) return;
		if (x >= n) return;
		if (y < 0) return;
		if (y>= m) return;
		if (c[x][y] == '#') return;
		if (used[x][y]) return;
		cnt--; used[x][y] = 1;
		dfs(x, y - 1);
		dfs(x, y + 1);
		dfs(x-1 , y);
		dfs(x+1 , y);
		dfs(x+1, y - 1);
		dfs(x-1, y + 1);
		dfs(x - 1, y-1);
		dfs(x + 1, y+1);
	}
int main()
{
//	freopen("cartin.txt", "r", stdin);
//	freopen("cartout.txt", "w", stdout);
	cin >> m >> n;
	cout << (m > n ? "No" : "Yes");
	fclose(stdin);
	fclose(stdout);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file