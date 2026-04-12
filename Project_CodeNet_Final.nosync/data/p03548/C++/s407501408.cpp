#include <bits/stdc++.h>
using namespace std;

int main() {
	int X, Y, Z;
	cin >> X >> Y >> Z;
  
  	int ans = 0;
	int total = X - Z;
  
  	while(total >= Y + Z){
      total -= Y + Z;
      ans ++;
    }
cout << ans << endl;
}