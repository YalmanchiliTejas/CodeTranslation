#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int r,g,b;
  cin >> r >> g >> b;
  int x = 2 * g + b;
  if (x%4)
    cout <<"NO";
  else
    cout << "YES";
  return 0;
}
