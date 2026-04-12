#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector> 
 
using namespace std;
 
int main() {
	int n, x, y;
	cin >> n;
	x = 800 * n;
	y = 200 * (n / 15);
	cout << x - y << endl;
	return 0;
}