#include "bits/stdc++.h"
using namespace std;

#define print(n) cout  << n << "\n"

int main() {
	int i, j , k;
	cin >> i >> j >> k;
	if ((i *100 + j*10 + k) % 4 == 0) {
		print("YES");
	}else {
		print("NO");
	}

	return 0;
}

