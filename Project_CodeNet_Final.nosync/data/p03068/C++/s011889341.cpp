#define _CRT_NO_SECURE_WARNINGS
#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <string>
#include <iomanip>
#include <set>
#include <random>
#include <queue>
#include <map>
#include <ctime>
#include <sstream>
#include <cstdlib>
using namespace std;
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std; int INF = 1e6; typedef long long ll; typedef double d; typedef unsigned long long ull;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int k;
	cin >> k;
	--k;
	char ss = s[k];
	for (int i = 0; i < n; ++i) {
		if (s[i] != ss) {
			s[i] = '*';
		}
	}
	cout << s << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}