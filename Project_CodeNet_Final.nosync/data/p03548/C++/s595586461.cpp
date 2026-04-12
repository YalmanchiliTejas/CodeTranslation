#include <iostream>

using namespace std;

int main()
{
  	int X, Y, Z;
  	cin >> X >> Y >> Z;
  	X -= Z;
  	int ans = 0;
  	while(X - (Y+Z) >= 0){
      	X -= Y+Z;
      	ans++;
    }
  	cout << ans;
  	return 0;
}