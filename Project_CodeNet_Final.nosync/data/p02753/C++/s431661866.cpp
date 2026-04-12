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
#define int long long
#define mod(int)(1000000007)
using namespace std;
int test[213456];
int ok[213456];
signed main() {
	int n, a = 0, b = 0, ans = 0; string s; cin >> s;
	for (int h = 0; h < s.size(); h++) {
		if (s[h] == 'A') { a = 1; }
		if (s[h] == 'B') { b = 1; }
	}
	if (a == 1 && b == 1) { cout << "Yes" << endl; }
	else { cout << "No" << endl; }
}