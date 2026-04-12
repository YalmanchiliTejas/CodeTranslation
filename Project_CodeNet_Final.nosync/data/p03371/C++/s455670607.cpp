#define _CRT_SECURE_NO_WARNINGS
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <bitset>
#include <utility>
#include <assert.h>
#include <regex>
using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
#define INF (1LL << 48)

struct PT { ll x; ll y; };
string to_s(ull x) { return to_string(x); }
string to_s(ll x) { return to_string(x); }
ll to_ll(const string& x) { return stoll(x); }
ull to_ull(const string& x) { return stoull(x); }




int main(int argc, char* argv[])
{
	for (;;) {
		ll A, B, C, X, Y;
		cin >> A >> B >> C >> X >> Y;
		if (cin.fail()) break;

		ll c1 = min(X, Y);
		ll c2 = max(X, Y);
		ll price_a = max((X - c1), 0LL) * A + max((Y - c1), 0LL) * B + c1 * 2 * C;
		ll price_b = max((X - c2), 0LL) * A + max((Y - c2), 0LL) * B + c2 * 2 * C;
		ll price_c = X * A + Y * B;

		cout << min(min(price_a, price_b), price_c) << endl;
	}

	return 0;
}