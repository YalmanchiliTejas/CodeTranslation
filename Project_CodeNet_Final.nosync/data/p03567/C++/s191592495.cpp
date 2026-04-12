#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>

typedef long long int lld;
typedef unsigned long long int ulld;
const int mod = 1000000007;

using namespace std;

int main (void) {
	ios::sync_with_stdio (false);
	string s;
	cin >> s;
	if (s.find ("AC") != string::npos) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}