#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <numeric>
#include <math.h>
#include <algorithm>
#include <functional>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <complex>
#define full(c) c.begin(), c.end()
#define vector2d(name,type,h,w,init) vector<vector<type>> name(h,vector<type>(w,init)) 
const int PRIME = 1000000007;
const int INT_INF = 2147483647;
const long long int LL_INF = 9223372036854775807;
const double PI = acos(-1);
const double EPS = 0.000000001;
typedef unsigned long long int ull;
typedef long long int ll;
using namespace std;

int main() {
	const int dx[4] = { 0,1,0,-1 };
	const int dy[4] = { -1,0,1,0 };
	while (1) {
		int k, i, j, rs, n, w, h;
		cin >> n;
		if (n == 0) break;
		vector<int> l(n);
		vector<int> t(n);
		vector<int> r(n);
		vector<int> b(n);
		for (i = 0; i < n; i++) {
			cin >> l[i] >> t[i] >> r[i] >> b[i];
		}
		{
			map<int, int> trans;
			for (i = 0; i < n; i++) {
				trans[l[i]] = 0;
				trans[r[i]] = 0;
			}
			i = 0;
			for (auto &p : trans) {
				p.second = i;
				i++;
			}
			w = 2 * i + 2;
			for (i = 0; i < n; i++) {
				l[i] = trans[l[i]];
				r[i] = trans[r[i]];
			}
		}
		{
			map<int, int> trans;
			for (i = 0; i < n; i++) {
				trans[t[i]] = 0;
				trans[b[i]] = 0;
			}
			i = 0;
			for (auto &p : trans) {
				p.second = i;
				i++;
			}
			h = 2 * i + 2;
			for (i = 0; i < n; i++) {
				t[i] = trans[t[i]];
				b[i] = trans[b[i]];
			}
		}
		vector2d(f, int, h, w, -1);
		for (k = 0; k < n; k++) {
			l[k] = 2 * l[k] + 1;
			r[k] = 2 * r[k] + 1;
			t[k] = 2 * t[k] + 1;
			b[k] = 2 * b[k] + 1;
			for (i = l[k]; i <= r[k]; i++) f[t[k]][i] = 0;
			for (i = l[k]; i <= r[k]; i++) f[b[k]][i] = 0;
			for (i = b[k]; i <= t[k]; i++) f[i][l[k]] = 0;
			for (i = b[k]; i <= t[k]; i++) f[i][r[k]] = 0;
		}
		/*
		for (auto d1 : f) {
			for (int d : d1) cout << d;
			cout << endl;
		}
		*/
		rs = 0;
		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				if (f[i][j] == -1) {
					rs++;
					queue<pair<int, int>> bfs;
					f[i][j] = rs;
					bfs.push({ i,j });
					while (!bfs.empty()) {
						int y = bfs.front().first;
						int x = bfs.front().second;
						bfs.pop();
						for (k = 0; k < 4; k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (nx < 0 || w <= nx || ny < 0 || h <= ny || f[ny][nx] != -1)
								continue;
							bfs.push({ ny,nx });
							f[ny][nx] = rs;
						}
					}
				}
			}
		}
		/*
		for (auto d1 : f) {
			for (int d : d1) cout << d;
			cout << endl;
		}
		*/
		cout << rs << endl;
	}
	return 0;
}



