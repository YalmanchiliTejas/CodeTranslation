#include <cstdio>
#include <cmath>
#include <limits>
#include <algorithm>
#include <cassert>
#include <vector>
#include <utility>
#include <string>
#include <iostream>

int main()
{
	using namespace std;
    int r,g,b;
	cin >> r >> g >> b;
    int n = g*10 + b;
    if (n%4==0) cout << "YES" << endl;
    else cout << "NO" << endl;
	return 0;
}
