#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <deque>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1000000007;
const int MAX_V = 201;
int now = 0;
int deco[1000];

void Sequence() {
	char c;
	cin >> c;
	char b[5] = { 'a','i','u','e','o' };
	for (size_t i = 0; i < 5; i++)
	{
		if (c == b[i]) {
			cout << "vowel" << endl;
			return;
		}
	}
	cout << "consonant" << endl;
}
int main() {
	Sequence();
	return 0;
}

