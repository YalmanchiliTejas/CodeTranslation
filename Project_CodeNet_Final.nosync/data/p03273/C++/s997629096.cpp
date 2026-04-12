#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cmath>

using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD (1000000007)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
#define swap(a, b, type) { type _tmp = a; a = b; b = _tmp; }
typedef long long ll;
typedef unsigned long long ull;

int main()
{
	int H, W;
	string ain, del;
	vector<string> a;
	string::iterator sit;
	vector<string>::iterator it;
	bool flag;

	cin >> H >> W;
	rep(i, H) {
		cin >> ain;
		a.push_back(ain);
	}

	rep(i, W) del.push_back('.');

	rep(i, H) {
		if (a[i] == del) {
			it = a.begin();
			it += i;
			a.erase(it);
			i--;
			H--;
		}
	}

	rep(j, W) {
		flag = true;

		rep(i, H) if (a[i][j] == '#') flag = false;
		if (flag) {
			rep(i, H) {
				sit = a[i].begin();
				sit += j;
				a[i].erase(sit);
			}
			j--;
			W--;
		}
	}

	rep(i, H) cout << a[i] << endl;

	return 0;
}
