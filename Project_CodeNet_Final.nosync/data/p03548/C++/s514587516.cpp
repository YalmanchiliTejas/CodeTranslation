#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>

typedef long long ll;
#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)

using namespace std;

int main(){
	ll X, Y, Z;
	cin >> X >> Y >> Z;
	
	cout << ((X - Z) / (Y + Z)) << endl;
}
