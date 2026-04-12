#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
long double p1, p2;
int main() {
	cin >> p1 >> p2;
	printf("%.15Lf\n", 1 / ((1 / p1) + (1 / p2)));
	return 0;
}