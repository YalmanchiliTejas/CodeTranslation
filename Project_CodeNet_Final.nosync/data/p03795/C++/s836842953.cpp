#include<iostream>
#define COST 800
#define DISCOUNT_PAR 15
#define DISCOUNT 200
using namespace std;

int main(int argc, char const *argv[]) {
  /* code */
  int N;
  int cash;

  cin >> N;
  cash = N/DISCOUNT_PAR;
  cout << (COST*N) - (DISCOUNT*cash) << endl;

  return 0;
}
