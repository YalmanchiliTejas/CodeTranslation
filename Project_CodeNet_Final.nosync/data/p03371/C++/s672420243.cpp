#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#define ll long long
#define vi vector<int>
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define pi 3.14159265359


ll gcd(ll a, ll b)
{
	ll c;
	while (a != 0) {
		c = a; a = b % a;  b = c;
	}
	return b;
}

int main() {
	ll A, B, C, X, Y, Z;
	ll D = 0;
	ll sum = 0;
	cin >> A >> B >> C >> X >> Y;

	if (X > Y) {
		D = Y;
		Y = X;
		X = D;
		D = B;
		B = A;
		A = D;
	}
	Z = Y;
	if (C * 2 < A + B) {
		Y -= X;
		sum = X * C * 2;
		sum += Y * B;
	}
	else {
		sum = A * X + B * Y;
	}
	if (C * Z * 2 < sum)sum = C * Z * 2;
	cout << sum;

	return 0;


}