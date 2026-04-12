// ISU

#include <iostream>

using namespace std;

int main(){
	int X, Y, Z;
	cin >> X >> Y >> Z;

	int res = 0;

	X -= Z; // left side space

	while(1){
		if (X >= Y+Z){
			X -= Y;
			res++;
			X -= Z; // right side space
		}else
			break;
	}

	cout << res << endl;

	return 0;
}