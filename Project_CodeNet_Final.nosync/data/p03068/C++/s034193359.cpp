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
ll h, w, n, m,k; string s; string sp;
char maze[60][60];
int dis[60][60];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	cin >> n >> s >> k; char key='a';
	for (int i = 0; i < n; i++) {
		if (i == k - 1) {
			key = s[i];
		}
	}
	string res;
	for (int i = 0; i < n; i++) {
		if (s[i] != key) {
			res += '*';
		}
		else {
			res += key;
		}
	}
	cout << res << endl;
}