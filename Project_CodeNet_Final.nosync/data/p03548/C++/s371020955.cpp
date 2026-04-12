#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <functional>
using namespace std;


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
    int x, y, z;
    cin >> x >> y >> z;
    int rest = x - z;
    int cnt = 0;
    while (rest >= y+z) {
        rest -= (y + z);
        cnt++;
    }
    cout << cnt << endl;
	return 0;
}