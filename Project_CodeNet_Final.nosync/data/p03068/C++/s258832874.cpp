#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <stdio.h>
using namespace std;

int n;
string s;
char s1;
int k;

int main() {

	cin >> n >> s >> k;
	s1 = s[k - 1];

	for (int i = 0; i < n; i++) {
		if (s1 != s[i]) s[i] = '*';
	}

	cout << s << endl;


	return 0;
}