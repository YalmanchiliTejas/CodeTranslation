#include <iostream>                                                                                                                      
#include <string>                                                                                                                        
#include <vector>                                                                                                                        
#include <math.h>                                                                                                                        
using namespace std;                                                                                                                     
int main() {                                                                                                                             
                                                                                                                                         
  long long N;                                                                                                                           
  cin >> N;                                                                                                                              
  vector<long long> A(N + 1);                                                                                                            
  long long total = 0;                                                                                                                   
  long long mod = (long long)(pow(10, 9) + 7);                                                                                           
                                                                                                                                         
  for (int i = 1; i < N + 1; i++) {                                                                                                      
    cin >> A[i];                                                                                                                         
    total += A[i];                                                                                                                       
    total %= mod;                                                                                                                        
  }                                                                                                                                      
  vector<long long> S(N + 1);                                                                                                            
  S[0] = total;                                                                                                                          
  for (int i = 1; i < N + 1; i++) {                                                                                                      
    S[i] = S[i - 1] - A[i];                                                                                                              
    if (S[i] < 0) S[i] += mod;                                                                                                           
    //cout << S[i] << endl;                                                                                                              
  }                                                                                                                                      
                                                                                                                                         
  long long sum = 0;                                                                                                                     
  for (int i = 1; i < N + 1; i++) {                                                                                                      
    sum += (A[i] * S[i]);                                                                                                                
    sum %= mod;                                                                                                                          
                                                                                                                                         
  }                                                                                                                                      
                                                                                                                                         
  cout << sum << endl;                                                                                                                   
                                                                                                                                         
  return 0;                                                                                                                              
                                                                                                                                         
}                 