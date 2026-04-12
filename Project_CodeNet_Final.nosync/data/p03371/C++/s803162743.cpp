#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int A, B, C, X, Y;
int main() {
  cin >> A >> B >> C >> X >> Y;
  int total = 0x7fffffff;
  for(int i=0;i<=100000;i++) {
    total=min(total, 
        i * 2 * C + max(0, X-i) *A+max(0,Y-i)*B);
  }
  cout << total << endl;
}