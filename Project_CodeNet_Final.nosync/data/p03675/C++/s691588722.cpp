#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <numeric>
#include <bitset>
#include <ext/algorithm>
#include <ext/numeric>
#define ffor(_a,_f,_t) for(int _a=(_f),__t=(_t);_a<__t;_a++)
#define all(_v) (_v).begin() , (_v).end()
#define sz size()
#define pb push_back
#define SET(__set, val) memset(__set, val, sizeof(__set))
#define FOR(__i, __n) ffor (__i, 0, __n)
typedef long long LL; using namespace std;

int b[1000000];

int main() {
	int lidx = 500000;
	int ridx = lidx - 1;
	bool right = true;
	int n, x;
	cin >> n;
	FOR (i, n) {
		cin >> x;
		if (right) {
			ridx++;
			b[ridx] = x;
		}
		else {
			lidx--;
			b[lidx] = x;
		}
		right ^= 1;
	}
	if (right) {
		ffor (i, lidx, ridx + 1)
			cout << b[i] << " ";
	}
	else {
		for (int i = ridx; i >= lidx; i--)
			cout << b[i] << " ";
	}
	cout << endl;
	return 0;
}