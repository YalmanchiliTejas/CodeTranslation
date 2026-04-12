#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  double a,b,c;
  cin >> a >> b;
  cout << setprecision(12) << 1 / (1/a + 1/b) << endl;
  return 0;
}
