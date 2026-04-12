#include <iostream>
using namespace std;

int main() {
  int n;
  int A[20];
  int high = 0;
  int can = 0;
  cin >> n;
  //cout << n << endl;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    //cout << A[i] << endl;
    if (A[i] >= high) {
      high = A[i];
      can += 1;
    }
  }
  
  cout << can << endl;
  
}