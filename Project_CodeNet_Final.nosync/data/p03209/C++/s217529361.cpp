#include <iostream>                                                                                                                                                          
using namespace std;                                                                                                                                                         
                                                                                                                                                                             
using int64 = long long;                                                                                                                                                     
                                                                                                                                                                             
constexpr int N = 50;                                                                                                                                                        
int64 height[N + 1];                                                                                                                                                         
int64 patty[N + 1];                                                                                                                                                          
                                                                                                                                                                             
void init() {                                                                                                                                                                
  height[0] = 1;                                                                                                                                                             
  patty[0] = 1;                                                                                                                                                              
  for (int64 l = 1; l <= N; ++l) {
    height[l] = 2 * height[l - 1] + 3;
    patty[l] = 2 * patty[l - 1] + 1;
  }
}

int64 solve(int64 n, int64 k) {
  int64 p = 0;
  if (k == height[n])
    return patty[n];

  if (k == 1)
    return 0;
  --k;
  if (k <= height[n - 1])
    return solve(n - 1, k);

  k -= height[n - 1];
  p += patty[n - 1];
  if (k == 1)
    return p + 1;

  --k;
  ++p;
  if (k <= height[n - 1])
    return p + solve(n - 1, k);
  p += patty[n - 1];
      
  return p;              
}                          

int main() {         
  int64 n, k;       
  init();    
  while (cin >> n >> k) {
    cout << solve(n, k) << "\n";
  }   
      
  return 0;              
}