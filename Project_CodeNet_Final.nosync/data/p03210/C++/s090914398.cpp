#include <iostream>                        
#include <stdlib.h>                        
                                           
using namespace std;                       
int main(void){                            
  int x;                                   
  cin >> x;                                
  if(x%2 == 1 && (x/2)> 0 &&(x/2) < 4){    
    cout << "YES" << endl;                 
  }                                        
  else{                                    
    cout << "NO" << endl;                  
  }                                        
  return 0;                                
}                                       