#include <iostream>
#include <cmath>

int main(){
  int A, B, C, X, Y;
  std::cin >> A >> B >> C >> X >> Y;    
  long long M = 0;
  int min = std::min(X, Y);
  if(2 * C >= A + B){
    M = min * A + min * B;
  }else{
    M = min * 2 * C;
  }

  int left = 0;
  left = std::max(X - min, Y - min);

  if(Y >= X){
    if(2 * C >= B){
      M += B * left;
    }else{
      M += 2 * C * left;
    }
  }else{
    if(2 * C >= A){
      M += A * left;
    }else{
      M += 2 * C * left;
    }
  }
  std::cout << M << std::endl;
  return 0;
}
