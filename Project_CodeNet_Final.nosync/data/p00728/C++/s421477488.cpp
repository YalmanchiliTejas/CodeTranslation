#include <iostream>
using namespace std;
int N, S;
int main () {
  while (cin >> N && N>0) {
    int sum = 0;
    int largest = 0;
    int smallest = 1000;
    for (int i=0; i<N; ++i) {
      cin >> S;
      sum += S;
      if (largest < S) largest = S;
      if (smallest > S) smallest = S;
    }
    int average = (sum - largest - smallest) / (N-2);
    cout << average << endl;
  }
}