#include "bits/stdc++.h"
using namespace std;

int main() {
    
    int x, y, z;
    cin >> x >> y >> z;
    for (int i=1; i<100005; i++) {
		if (y * i + z * (i + 1) > x) {
			cout << i-1 << endl;
			exit(0);
		}
	}
    
}
