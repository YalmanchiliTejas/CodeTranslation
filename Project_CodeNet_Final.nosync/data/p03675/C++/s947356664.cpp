#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<iostream>
#include<cctype>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include <algorithm>
#include<math.h>
#include<set>
#include<map>
#include <sstream>
#include<iomanip>
#include <ctype.h>

//#include<bits/stdc++.h>


using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>a, b;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (i % 2)a.push_back(x);
		else b.push_back(x);
	}
	if (n % 2) {
		reverse(a.begin(), a.end());
		for (int i = 0; i < a.size(); i++)cout << a[i] << " ";
		for (int i = 0; i < b.size(); i++) { cout << b[i]; if (i != b.size() - 1)cout << " "; }
		cout << endl;
	}
	else {
		reverse(b.begin(), b.end());
		for (int i = 0; i < b.size(); i++)cout << b[i] << " ";
		for (int i = 0; i < a.size(); i++) { cout << a[i]; if (i != a.size() - 1)cout << " "; }
		cout << endl;
	}

	return 0;
}