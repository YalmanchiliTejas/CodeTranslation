#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <functional>
#include <string>
#include <cstdlib>
#include <numeric>
#include <cstdbool>
#include <map> 
#include<set>
#include<queue>

typedef long long ll;


#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1000000000000000;
typedef pair<int, int> P;
ll ma = 1000000000 + 7;
ll h, w, n, m; string s;
char maze[60][60];
int dis[60][60];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int res = 1;
	int k = h[0];
	for (int i = 1; i < n; i++) {
		chmax(k, h[i-1]);
		if (h[i] >= k) {
			res++;
		}
	}
	cout << res << endl;
}