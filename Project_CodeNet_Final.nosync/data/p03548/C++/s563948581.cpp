#include <iostream>
using namespace std;

int main() {
	int X, Y, Z;
	cin >> X >> Y >> Z;
	
	X = X - Z*2;
	int cnt;
	while(true){
		if(X>=Y+Z){
			X -=Y;
			cnt++;
			X -= Z;
		}
		else if(X==Y){
			cnt++;
			X-=Y;
		}
		else break;
	}
	
	cout << cnt;
	cout << endl;
	
	
	return 0;
}