#include <iostream>

int main () {
  int A, B, AB, a, b;
  std::cin >> A >> B >> AB >> a >> b;
  
  if ( A > B ) { 
    std::swap(A,B);
    std::swap(a,b);  
  }   
  
  int max_number = (a > b ) ? a:b;
  if (AB <= A ) {
    if (AB <= B/2) {
      std::cout << AB * 2 * (max_number ) << std::endl;
    }
    else {
      if (a > b ) {
        std::cout << AB * 2 * b + A * (a-b) << std::endl;
      }
      else {
        std::cout << AB * 2 * a + B * (b-a) << std::endl;  
      }
    }
  }
  else {
    if (AB <= (A + B) / 2  ) {
      if (a < b ) {
        std::cout << AB * 2 * a + B * (b-a) << std::endl; 
      }
      else {
        std::cout << AB * 2 * b + A * (a-b) << std::endl;
      }
    }  
    else {
      std::cout << A * a + B * b << std::endl;  
    }
  }
}