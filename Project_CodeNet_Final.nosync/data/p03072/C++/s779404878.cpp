#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <sstream>
#include <set>
#include <map>
#define LLMAX 9223372036854775807

using namespace std;
using ll = long long;

int main() {
	ll argN;
	cin >> argN;

	vector<ll> argH(argN);
	for (auto itr = argH.begin(); itr != argH.end(); ++itr) {
		cin >> *itr;
	}

	ll ret = 1;
	for (ll i = 1; i < argN; ++i) {
		bool visible = true;
		for (ll j = i - 1; j >= 0; --j) {
			visible &= (argH.at(j) <= argH.at(i));
		}
		if (visible) {
			ret++;
		}
	}

	cout << ret << endl;
}