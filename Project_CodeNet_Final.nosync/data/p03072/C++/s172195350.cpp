#include <string>
#include <algorithm>
#include <vector> 
#include <math.h>
#include <iostream>
using namespace std;
long long mod = 1000000000 + 7;


int main()
{
	int n;
	cin >> n ;
	int ans = 0;
	int ma = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (ma <= a) {
			ma = a;
			ans++;
		}
	}
	
	cout << ans << endl;
	return 0;

}
