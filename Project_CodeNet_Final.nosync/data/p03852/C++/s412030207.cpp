//#include "IntMod.h"
//typedef IntMod<1000000007> MInt;

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>

using namespace std;
#define REP(i,a,n) for(int i = a; i < n; ++i)
#define REPM(i,n,a) for(int i = n - 1; i >= a; --i)
#define EPS 0.0001
#define INF 0x3FFFFFFF
#define INFD 1.0e+308
typedef long long LL;
typedef unsigned long long ULL;

typedef pair<LL, LL> PP;


char a;
int main() {
	cin >> a;
	REP(i, 0, 5) {
		if (a == "aiueo"[i]) {
			cout << "vowel" << endl;
			return 0;
		}
	}
	cout << "consonant" << endl;
	return 0;
}