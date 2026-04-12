#include<iostream>
using namespace std;

int main() {
  int N;
  int loss;

  cin >> N;
  loss = N/15;

  cout << N*800 - loss*200 << endl;

  return 0;
}
