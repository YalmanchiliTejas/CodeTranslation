#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <iomanip>
#include <math.h> 

using namespace std;

int main() {
	int i, j, x, y, z;
	int cnt;

	cin >> x >> y >> z;

	for (i = z, cnt = 0; i <= x; i += (y+z)) {

		cnt++;
	}


	cout << cnt-1 << endl;





	return 0;
}