#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <regex>
#include <stack>
#include <queue>
#include <vector>
#define MAX_N 100
#define INF 10000000

using namespace std;


int n;
string s;
int a[200000];

void solve() {
	string a = "No";
	for (int i = 0; i < s.length()-1; i++) {
		if (s[i] == 'A'&&s[i + 1] == 'C') a = "Yes";
	}
	cout << a << endl;
}

int main() {
	cin >> s;
	solve();
	return 0;
}