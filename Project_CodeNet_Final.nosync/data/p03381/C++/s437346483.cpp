#include <iostream>
#include <algorithm>
#include<string>
#include<cmath>
#include<stack>
#include <vector>
#include<queue>
#include <random>
#include <cstdint>
#include <bitset>
#include <iomanip>
using namespace std;



int main() {
	int n, a[200000], ans,sorteda[200000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sorteda[i] = a[i];
	}
	sort(sorteda, sorteda + n);
	for (int i = 0; i < n; i++) {
		ans = ((a[i] <= sorteda[n / 2 - 1]) ? sorteda[n / 2 ] : sorteda[n / 2-1]);
		cout << ans << endl;
	}
	return 0;
}


