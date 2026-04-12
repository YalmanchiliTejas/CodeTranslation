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
#include<iomanip>

//#include<bits/stdc++.h>


using namespace std;



int main() {

	long long int ans = 0;
	int n;
	cin >> n;
	ans += n * 800;
	ans -= 200 * (n / 15);
	cout << ans << endl;

	return 0;

}


