#include <iostream>
using namespace std;

int main(){
	int X, Y, Z, W=0;
	cin >> X >> Y >> Z;
	W=X/(Y+Z);
	if(X%(Y+Z)<Z) W--;
	cout << W;
}