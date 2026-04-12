#include <bits/stdc++.h>
using namespace std;

int main() {
	int X, Y, Z; cin >> X >> Y >> Z;
	X -= Z;
	Y += Z;
	int i = 0;
	while(true){
		X -= Y;
		if( X >= 0 ){
			i++;
		} else {
			cout << i << endl;
			return 0;
		}
	}
}