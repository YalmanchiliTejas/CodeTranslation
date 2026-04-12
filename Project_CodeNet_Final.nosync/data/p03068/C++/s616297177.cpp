#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <stdio.h>
using namespace std;

int n, k;
char x;
char s[12];

int main() {

	cin >> n >> s >> k;

	x = s[k - 1];

	for (int i = 0; i < n; i++) {
		if (x != s[i]) s[i] = '*';
	}

	cout << s << endl;

	return 0;
}
