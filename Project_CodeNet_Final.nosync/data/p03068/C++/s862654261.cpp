#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#define ll long long
#define REP(i, x) for(int (i) = 0; (i) < (x); (i) ++)
#define pi 3.1415926535
using namespace std;

int main() {
	int n, k;
	string s;
	cin >> n >> s >> k;
	char key;
	key = s[k - 1];
	REP(i, n) {
		if (s[i] == key) {
			continue;
		}
		else {
			s[i] = '*';
		}
	}
	cout << s << endl;
	return 0;
}