#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main(void){
	int x, y, z;

	cin >> x >> y >> z;

/*	if (x % (y + z) >= z){
		if (x % (y + z) >= y){
			cout << x/(y + z) + 1 << endl;
		}
		else 
			cout << x / (y + z) << endl;
	}
	else {
		if (x % (y + z) >= y){
			cout << x/(y + z) << endl;
		}
		else 
			cout << x / (y + z) - 1 << endl;		
	}*/

	cout << (x - z) / (y + z) << endl;


	return 0;
}