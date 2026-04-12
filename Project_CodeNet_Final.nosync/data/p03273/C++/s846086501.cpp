#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <functional>
#define rep(i,n) for(int i=0;i<n;++i)

using namespace std;
using ll = long long;

ll n, m, o, add, ans, A[1010101];
string s, str;
char c[101][101];
int main() {
	cin >> n >> m;
	rep(i, n) {
		rep(j, m) {
			cin >> c[i][j];
			if (c[i][j]=='.') add++;
		}
		if (add == m) rep(j, m) c[i][j] = '0';
		add = 0;
	}
	rep(j, m) {
		rep(i, n) {
			if (c[i][j] == '.' || c[i][j] == '0') add++;
		}
		if (add == n) rep(i, n) c[i][j] = '0';
		add = 0;
	}
	rep(i, n) {
		rep(j, m) {
			if (c[i][j] != '0') cout << c[i][j];
            else add++;
        }
        if(add!=m) cout << endl;
        add=0;
	}
	return 0;
}