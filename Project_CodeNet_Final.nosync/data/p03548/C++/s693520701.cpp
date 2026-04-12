#include<bits/stdc++.h>
using namespace std;

int main() {
	int x,y,z;
  	cin >> x >> y >> z;
  
  	int remain = x - z;
  	int ans = 0;
  	
  	while(remain >= y + z) {
    	remain -= (y + z);
      	ans++;
    }
  
  	cout << ans << endl;
}