#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  int a, b, c;
  cin >> a;
  double ans, ra, rb;
  if(a <= 7 && a % 2 == 1 && a != 1){
    cout << "YES";
  }else{
    cout << "NO";
  }
  return 0;
}
