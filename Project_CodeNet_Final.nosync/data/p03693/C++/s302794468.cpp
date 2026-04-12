#define _USE_MATH_DEFINES
#include<stdio.h>
#include<string>
#include<iostream>
#include<cctype>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<math.h>
#include<set>
#include<map>
#include<iomanip>
#include<functional>
using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int r, g, b; cin >> r >> g >> b;
	if ((100*r + 10*g + b) % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}