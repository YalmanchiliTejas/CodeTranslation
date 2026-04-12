#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#pragma warning(disable:4996)
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
#include <set>
#include <map>
#include <iomanip> 
#include <ctime>
#include <numeric>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<string, int> P;
typedef vector<vector<int>> Graph;

const double PI = 3.14159265358979323846;

const int mod = 1000000007;

int main(int argc, char *args[]) {
	string s;
	cin >> s;
	if (s[0] == s[1] && s[1] == s[2]) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
	return 0;
}