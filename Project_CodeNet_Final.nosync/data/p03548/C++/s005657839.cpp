#include <iostream> 
#include <stdlib.h> 
#include <string.h> 
#include <string> 
#include <sstream>
#include <cstring> 
#include<cmath>
using namespace std;
int main() {
	int x, y, z;
	cin >> x >> y >> z;
	if (y + z * 2 <= x) {
		
		cout << (x - z) / (y + z);
	}
	
	return 0;

}