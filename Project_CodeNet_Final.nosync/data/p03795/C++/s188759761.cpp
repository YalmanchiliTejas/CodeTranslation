#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <new>
#include <map>

using namespace std;
 
int main() {
	int n,a,x,y,ans;
	cin >> n;
	x = 800 * n;
	a = n / 15;
	y = 200 * a;
	ans = x - y;
	cout << ans << endl;
	return 0;
}