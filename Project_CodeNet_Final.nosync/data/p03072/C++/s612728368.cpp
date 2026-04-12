#include <iostream>              
                                 
using namespace std;             
                                 
int main(void){                  
  int N,max,count;               
  cin >> N;                      
  int H[N];                      
  for(int i = 0; i < N;++i){     
    cin >> H[i];                 
  }                              
  max = 0;                       
  count = 0;                     
  for(int i = 0; i < N;++i){     
      if(max <= H[i]){           
        max = H[i];              
        count++;                 
      }                          
  }                              
  cout << count << endl;         
  return 0;                      
}                                