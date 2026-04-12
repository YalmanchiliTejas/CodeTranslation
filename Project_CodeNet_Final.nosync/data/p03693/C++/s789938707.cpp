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
ll test[1234][1234];
signed main() {
	ll n = 0, m = 0, k, l, cnt = 0, z = 0; cin >> k >> l >> n;
	cnt = k * 100 + l * 10 + n;
	if (cnt % 4 == 0) { cout << "YES" << endl; }
	else { cout << "NO" << endl; }
	cin >> n; return 0;
}