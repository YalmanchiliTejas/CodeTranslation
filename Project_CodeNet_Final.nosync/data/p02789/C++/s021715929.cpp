//
//  main.cpp
//  A
//
//  Created by Hashizo on 2020/01/19.
//  Copyright © 2020 Hashizo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>
#include <cmath>

using namespace std;
 
#undef LONG_MAX
#undef LONG_MIN
 
#define LONG_MAX    9223372036854775807
#define LONG_MIN    (-LONG_MAX  -1)
 
#define ll long long
 
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
 
#define SORT(c) sort((c).begin(), (c).end())
#define REVERSE(v) reverse((v).begin(), (v).end())


int main(int argc, const char * argv[]) {


	ll n,m;
	cin >> n >> m;

	if (n == m) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	
	return 0;
}
