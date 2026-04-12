#include <bits/stdc++.h>
using namespace std;

int n, x, z, y, k;

int main (){
	cin >> n;
	x = n*800;
	z = n/15;
	y = z*200;
	k = x - y;
	
	cout << k;
	return 0;
}