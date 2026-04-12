#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <istream>
#include <map>
#include <set>
#include <queue>
#define rep0(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i < (n); ++i)
#define REP(i,a,b) for (int i = a; i < (b); ++i) 
typedef long long ll;
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	/*
	/
	/
	/
	*/
	ll a, b, c;
	cin >> a >> b >> c;
	cout<< (a - c) / (b + c) << endl;
	return 0;
}