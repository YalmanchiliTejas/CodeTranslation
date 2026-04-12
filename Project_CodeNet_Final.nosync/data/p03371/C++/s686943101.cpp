#include<bits/stdc++.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main(){
  int a, b, c, x, y;

  cin >> a >> b >> c >> x >> y;

  int total1, total2, total3;

  // if(((a+b)/2 > c) && (min(a,b) < c)){                                                                     
  //   if(x < y){                                                                                             
  //     total = x*2*c + (y-x)*b;                                                                             
  //    }                                                                                                     
  //   else{                                                                                                  
  //     total = y*2*c + (x-y)*a;                                                                             
  //    }                                                                                                     
  // }                                                                                                        
  // else if(((a+b)/2 <= c) && (min(a,b) < c)){                                                               
  //   total = a*x + b*y;                                                                                     
  //  }                                                                                                       
  // else{                                                                                                    
  //   total = max(x,y)*2*c;                                                                                  
  // }                                                                                                        

  // if(max(x,y)*2*c < total){                                                                                
  //   total = max(x,y)*2*c;                                                                                  
  // }                                                                                                        

  if(x < y){
    total1 = x*2*c + (y-x)*b;
  }
  else{
    total1 = y*2*c + (x-y)*a;
  }
  total2 = a*x + b*y;
  total3 = max(x,y)*2*c;

  cout << min(total1,min(total2,total3)) << endl;

  return 0;
}
