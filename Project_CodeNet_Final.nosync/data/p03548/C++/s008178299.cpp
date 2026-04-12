#include <bits/stdc++.h>
using namespace std;

int main() {
	long long x,y,z;
	cin >> x >> y >> z;
	x-=z;
	cout << x/(y+z);
}