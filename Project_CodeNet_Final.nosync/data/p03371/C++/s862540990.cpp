#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  
  long long res = 1000000000;
  
  for(int i_ab = 0; i_ab <= 100000; ++i_ab){
	int a_left = max(x - i_ab, 0);
    int b_left = max(y - i_ab, 0);
    
    long long price = i_ab * c * 2 + a * a_left + b * b_left;
    
    if(price < res){
      res = price;
    }
  }

  cout << res << endl;
}