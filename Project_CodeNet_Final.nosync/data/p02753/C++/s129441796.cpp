#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <algorithm>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <tuple>
#include <thread>///////////////////

#define rep(i,m,n) for(int i=(m);i<(n);++i)
#define rem(i,m,n) for(int i=(m);i>(n);--i)
#define MOD 1000000007

using namespace std;

using ll = long long int;
using std::swap;

vector<int> v;
vector<int> w;
vector<long long int> vll;
vector<long long int> wll;
//vector<vector<int>> vec(50, vector<int>(4, 0));
vector<vector<int>> vv;

int N, Y;
int mode = 0;

//tuple<int, int, int> calc(int A, int B, int C) {}



int main() {
	string S;
	cin >> S;
	if (S == "AAA" || S == "BBB")cout << "No" << '\n';
	else cout << "Yes" << '\n';

	return 0;
}