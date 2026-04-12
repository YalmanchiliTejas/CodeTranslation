#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <queue>
#include <algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include <iomanip>
#include<deque>
#include<stack>
#include<set>
#include <numeric>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
//typedef pair<int, int> P;
const int INF = 111111111;
const ll LLINF = 1e17 + 1;
const int DX[9] = { 0,0,1,-1, 1, 1, -1, -1, 0 }; // 4;４近傍
const int DY[9] = { 1,-1,0,0, 1, -1, 1, -1, 0 }; // 8:８近傍 9:(0,0)を含む
const int DIV = 1000000007; //10^9 + 7
const double PI = 3.14159265358979323846264338327950288;


int main() {

	//==================================
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	//==================================

	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	// Cを買うならA,Bを買ったほうがいい
	if (A + B <= 2 * C) {
		cout << A * X + B * Y;
		return 0;
	}

	//　A,Bを買うならCを買ったほうがいい
	else if (A >= 2 * C && X>=Y) {
		cout << C * 2 * X;
		return 0;
	}
	else if (B >= 2 * C && Y >= X) {
		cout << C * 2 * Y;
	}

	//　ミックス
	else {
		cout << C * 2 * min(X, Y) + A * (X - min(X, Y)) + B * (Y - min(X, Y));
		return 0;
	}









}	
