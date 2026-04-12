#include<iostream>
using namespace std;

int main(){
	int x, y, z;
	cin >> x >> y >> z;
	if(x < y + 2 * z) {
		cout << 0;
		return 0;
	}
	cout << 1 + (x - y - 2*z) / (y + z);
	return 0;
}

