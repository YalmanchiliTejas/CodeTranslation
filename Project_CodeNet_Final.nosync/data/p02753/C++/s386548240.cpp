#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <utility>
using namespace std;
 
int main() {
	char a[3];
	for(int i = 0; i< 3; i++) {
		cin >> a[i];
	}

	for(int i = 1; i< 3; i++) {
		if (a[i] != a[i-1]) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;

}
