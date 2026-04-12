#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int X, Y, Z, ans;

  cin >> X >> Y >> Z;

  ans = (X - Z) / (Y + Z); 
  cout << ans << endl;

	return 0;
}
