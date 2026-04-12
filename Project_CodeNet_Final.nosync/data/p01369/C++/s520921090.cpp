#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <complex>
#include <vector>
#include <cstdio>
#include <cmath>
#include <time.h>
#define all(c) ((c).begin(),(c).end())
#define rall(c) (c).rbegin(),(c).rend()
#define sort(v,n) sort(v,v+n)
#define vsort(v) sort(v.begin(),v.end())
#define vvsort(v) sort(v.begin(),v.end(),greater<int>())
#define ll long long
#define pb(a) push_back(a)
#define fi first
#define se second
#define inf 999999999
using namespace std;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
//---------------------------------------------------------------------------------------------//
string s;
bool jadge(char a) {
	char b[11] = { 'y','h','n','u','j','m','i','k','o','l','p' };
	for (int i = 0; i < 11; i++) {
		if (a == b[i])return 1;
	}
	return 0;
}


int main() {
	while (cin >> s) {
		if (s == "#")return 0;
		int m = s.length();
		bool b[33];
		for (int i = 0; i < m; i++) {
			if (jadge(s[i])) {
				b[i] = 1;
			}
			else {
				b[i] = 0;
			}
		}
		int cont = 0;
		for (int i = 1; i < m; i++) {
			if (b[i] != b[i - 1]) {
				cont++;
			}
		}
		cout << cont << endl;
	}
}