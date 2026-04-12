#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
//#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 10000000000000000;
const ll mod = 1000000007;
ll test[12345678];
signed main() {
	ll n = 0, m = 0, k, l, cnt = 0, z = 0; string s; cin >> s;
	for (int h = 0; h < 3; h++) {
		if (s[h] == 'A') { n++; }
		else { m++; }
	}
	if (n == 3 || m == 3) { cout << "No" << endl; }
	else { cout << "Yes" << endl; }
	cin >> n; return 0;
}