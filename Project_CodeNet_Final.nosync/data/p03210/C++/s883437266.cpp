#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<functional>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 3 || n == 5 || n == 7) { cout << "YES" << endl; }
	else { cout << "NO" << endl; }
	return 0;
}