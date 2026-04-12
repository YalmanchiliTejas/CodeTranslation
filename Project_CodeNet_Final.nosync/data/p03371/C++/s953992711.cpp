#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,x,y;
  int result = 0;
  cin >> a >> b >> c >> x >> y;
  
  if(2 * c < a + b) {
    if(c < a && c < b){
    	result += std::max(x,y) * c * 2;
    }else{
      if(x > y){
      	result += 2 * c * y;
      	result += (x-y) * a;
      }else{
     	result += 2 * c * x;
     	result += (y-x) * b;
      }
    }
    
  }else{
  	result = std::min(a * x + y * b, std::max(x,y) * c * 2);
  }
  
  if(x > y){
  result = std::min({a * x + y * b,std::max(x,y) * c * 2,2 * c * y+(x-y)*a});
  }else{
  result = std::min({a * x + y * b,std::max(x,y) * c * 2,2 * c * x+(y-x)*b});
  }
  
  cout << result << endl;
  
  return 0;
}