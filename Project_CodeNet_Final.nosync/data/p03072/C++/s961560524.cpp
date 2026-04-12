#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
using namespace std;


int main() {
	//cout << fixed << setprecision(10);
	long long int n, m, a, b, c, d, x, h[30], w, cou = 1,Max=0;
	cin >>n ;
	cin >> h[1];
	Max = h[1];
	for (int i = 2; i <= n; i++) {
		cin >> h[i];
		if (Max <= h[i]) { Max = h[i]; cou++; }
	}
	cout << cou;
	
}

