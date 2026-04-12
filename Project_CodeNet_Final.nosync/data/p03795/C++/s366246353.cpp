#include <iostream>
#define PRICE 800
#define REFUND 200
#define REFUND_NUM 15
using namespace std;

int main(){
  int N;

  cin >> N;
  cout << (N * PRICE - REFUND * (N / REFUND_NUM)) << endl;
  return 0;
}