#include<iostream>
#include<iomanip>
#include<string>


#define rep(i,n) for(int i = 0; i < n; ++i)
using namespace std;

int main(void){
  int r1, r2;
  cin >> r1 >> r2;
  cout << setprecision(9);
  cout << 1.0/(1.0/r1 + 1.0/r2) << endl;
  return 0;
}

