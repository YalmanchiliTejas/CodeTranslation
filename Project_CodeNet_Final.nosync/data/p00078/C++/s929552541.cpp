#include <iostream>
#include <iomanip>
#include <cassert>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <bitset>
#include <sstream>
#include <istream>
#include <cmath>
#include <cstdio>

using namespace std;

#define vci vector<int>
#define vcs vector<string>
#define pb push_back
#define sz size()
#define mapii map<int, int>
#define mapci map<char, int>
#define mapsi map<string, int>
#define all(x) x.begin(), x.end()
#define minit(a, i) memset(a, i, sizeof(a));

#define for_(i, a, b) for (int i=(int)a; i<(int)b; i++)
#define for_d(i, a, b) for (int i=(int)a-1; i>=b; i--)
#define for_r(i, a, b, c) for (int i=(int)a; i<(int)b; i += c)
#define for_dr(i, a, b, c) for (int i=(int)a-1; i>=b; i -= c)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

typedef long long ll;
typedef double D;

const int iINF = 2147483647;
const ll lINF = 9223372036854775807;

template <class T> inline void dbg(T t) { cout << t << endl; }



vector< vci > solve(int n) {
	vector< vci > ret(n, vci(n, -1));
	int y = n/2 + 1, x = n/2;
	ret[y][x] = 1;
	
	for_(i, 2, n*n+1) {
		y = (y + 1)%n; x = (x + 1)%n;
		
		while (ret[y][x]!=-1) {
			y = (y+1)%n; x = (x-1 + n)%n;
		}
		
		ret[y][x] = i;
	}
	
	return ret;
}

int main() {
	int n;
	
	while (1) {
		cin >> n; if (n==0) break;
		
		vector< vci > ans = solve(n);
		
		for_(i, 0, n) {
			for_(j, 0, n) {
				printf("%4d", ans[i][j]);
			}
			cout << endl;
		}
	}
	
	return 0;
}