#include <iomanip>
#include <random>
#include <time.h>
#include <vector>
#include <queue>
#include <functional>
#include <map>
#include <string>
#include <cstdlib>
#include <typeinfo>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <list>
#include <stack>
#include <set>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
using namespace std;
int main() {
	ll a, b, c, ans = 1;
	cin >> a >> b >> c;
	if (b <= c) {
		if (b >= a)cout << 1 << endl;
		else cout << -1 << endl;
	}
	else {
		a -= b;
		if (a <= 0)cout << 1 << endl;
		else cout << 1 + 2*((a + b - c - 1) / (b - c)) << endl;
	}
	return 0;
}