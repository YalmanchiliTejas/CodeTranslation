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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 10e9;
void RGBCards(){
	
	int r, g, b;
	cin >> r >> g >> b;
	cout << ((r * 100 + g * 10 + b) % 4 == 0 ? "YES" : "NO") << endl;
}

int main() {
	RGBCards();
	return 0;
}

