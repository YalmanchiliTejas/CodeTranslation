#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
   	int x, y, z, i = 0;
  	cin >> x >> y >> z;
  	while(true){
    	i++;
      	if((y*i) + z * (i+1) > x){
        	cout << i - 1 << endl;
          	return 0;
        }
    }
    return 0;
}