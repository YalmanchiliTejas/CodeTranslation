#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  int b;
  int c;
  int target;
  
  cin >> a >> b >> c;
  
  target = 100*a + 10 * b + c ;
  target = target%4 ;
  
  if(target == 0){
  
    cout << "YES" << endl;    
  }
  
  else{
  
    cout << "NO" << endl;
    
  } 
}