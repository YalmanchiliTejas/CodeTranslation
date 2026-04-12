#include <bits/stdc++.h>
using namespace std;

int main (){
	int n, x, y;
	
	x = 800;
	y = 200;
	
	cin >> n;
	
	x = 800*n;
	y = n/15*y;
	
	cout << x-y << endl;
}