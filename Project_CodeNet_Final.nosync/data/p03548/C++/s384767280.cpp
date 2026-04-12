#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<string.h>
#include<complex>
#include<math.h>
using namespace std;
typedef long long int llint;
#define rep(i,n) for(int i=0;i<n;i++)
int main() {
	int x, y, z;
	cin >> x >> y >> z;
	x -= z;
	cout << x / (y + z) << endl;
	return 0;
}