#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define MOD 1000000007
using namespace std;

int main(void) {
	double r1, r2;
	double p;
	cin >> r1 >> r2;
	p = (r1*r2) / (r1 + r2);
	printf("%15.8lf\n", p);
	return 0;
}