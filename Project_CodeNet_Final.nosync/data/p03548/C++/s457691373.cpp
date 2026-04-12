#include <iostream>
using namespace std;

int main(){
	int X, Y, Z;
	cin >> X >> Y >> Z;
	int ans = 0;
	X -= Z;
	ans += X / (Y + Z);
	cout << ans << endl;
}
