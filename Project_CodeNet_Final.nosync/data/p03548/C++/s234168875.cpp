#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	int x,y,z;
	cin >> x >> y >> z;
	x-=z;
	int ans=0;
	ans+= x/(y+z);

	
	cout << ans << endl;
	return 0;
}