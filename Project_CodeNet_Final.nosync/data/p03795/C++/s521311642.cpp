//Restaurant.cpp (A)
#include <iostream>
#include <string>
using namespace std;

int main(){
  int N;
  cin >> N;
  int Ans = 0;
  Ans = N*800;
  Ans -= N/15*200;
  printf("%d\n",Ans );
  return 0;
}
