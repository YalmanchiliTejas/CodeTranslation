#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;

int main() {
	string s;
	cin >> s;

	if (s[0] != s[1] || s[1] != s[2] || s[2] != s[0])
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}