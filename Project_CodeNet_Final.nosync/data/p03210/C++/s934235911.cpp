#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;

#define REP(i,n) for(int i=0;i<n;i++)
#define EPS (1e-9)
#define INF (1e9 + 1)
#define PI (acos(-1))

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	ll c = (b / gcd(a, b));
	return c * a;
}

ll A, B, N, sum = 0;

int X;

int main() {
	cin >> X;
	if (X == 3 || X == 5 || X == 7) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}