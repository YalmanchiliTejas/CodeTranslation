#include <iostream>
using namespace std;

int main(){
 int x,y,a,b,c,ans,flag;
  ans = 0;
  cin >> a >> b >> c >> x >> y;
  
  if(a+b > c*2){
	if(x < y){
      ans += c*x*2;
    }
    else{
      ans += c*y*2;
    }
    flag = 0;
  }
  else{
	if(x < y){
      ans += a*x;
    }
    else{
      ans += b*y;
    }
    flag = 1;
  }
  
  if(flag == 0){
    if(y < x){
      if((x-y)*a > (x-y)*2*c){
        ans += (x-y)*2*c;
      }
      else{
        ans += (x-y)*a;
      }
    }
    else{
      if((y-x)*b > (y-x)*2*c){
        ans += (y-x)*2*c;
      }
      else{
        ans += (y-x)*b;
      }
    }
  }
  else if(flag == 1){
    if(y < x){
      if(x*a > x*2*c){
        ans += x*2*c;
      }
      else{
        ans += x*a;
      }
    }
    else{
      if(y*b > y*2*c){
        ans += y*2*c;
      }
      else{
        ans += y*b;
      }
    }
  }
  	
  
  cout << ans << endl;
 return 0; 
}