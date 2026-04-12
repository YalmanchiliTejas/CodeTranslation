#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

#define REP(i,n) for(int i=0;(i)<(n);(i)++)
#define ll long long

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << (((100*a+10*b+c)%4==0) ? "YES" : "NO") << endl;
	return 0;
}