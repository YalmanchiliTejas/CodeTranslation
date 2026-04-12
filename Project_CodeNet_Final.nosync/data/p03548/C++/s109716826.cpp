#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;

int main() {
	double x,y,z;
	cin >> x>>y>>z;

	x=x-z;
	z=z+y;
	cout << floor(x/z) << endl;
	return 0;
}

