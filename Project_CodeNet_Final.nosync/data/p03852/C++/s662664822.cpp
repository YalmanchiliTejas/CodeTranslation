#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <cstdio>
#include <cmath>
using namespace std;

string check(char c) {
	char check[5] = { 'a','i','u','e','o' };
	for (int i = 0; i < 5; i++) {
		if (c == check[i])return "vowel";
	}
	return "consonant";
}

int main() {
	char c;
	cin >> c;
	cout << check(c) << endl;
	return 0;
}