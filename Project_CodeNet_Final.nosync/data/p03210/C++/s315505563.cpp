#include <iostream>

using namespace std;

int main(void){
  int X=10;
  while(X<1 || 9<X)
    cin >> X;

  int flag[9] = {0};
  flag[2] = 1;
  flag[4] = 1;
  flag[6] = 1;

  if(flag[X-1])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
