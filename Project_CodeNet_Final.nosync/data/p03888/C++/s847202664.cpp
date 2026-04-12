#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

int main(){

  double R1, R2; cin >> R1 >> R2;
  cout << setprecision(16) << (R1 * R2) / (R1 + R2) << endl;

  return 0;
}