#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define INF 2000000000
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int, int> P;
const ll MOD=1000000007;
using Graph = vector<vector<int>>;



int main() {
	string s;
	cin >> s;
	if (s[0] == s[1] && s[1] == s[2]) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	return 0;
}