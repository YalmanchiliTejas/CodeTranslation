#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

int main(){
  double a,b;
  double c;
  cin >> a >> b;

  c = double(a*b/(a+b));

  std::cout << std::setprecision(10) << c << std::endl;
  return 0;
}
