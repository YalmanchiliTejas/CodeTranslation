#include <iostream>

using namespace std;

int main(){
  int a,b,sum=0;
  cin >> a;

  b = a/15;

  sum += a*800 - 200*b;

  cout << sum << endl;
        return 0;
}