#include <iostream>
#include <vector>

using namespace std;

int main(){
  int r, g, b;
  cin >> r >> g >> b;
  int tmp = r * 100 + g * 10 + b;
  
  if(tmp % 4 == 0) cout << "YES";
  else cout << "NO";
}
