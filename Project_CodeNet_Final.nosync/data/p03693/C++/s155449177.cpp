#include <iostream>
using namespace std;

int main()
{
  int a,b,c;
  cin >> a >> b >> c;
  int x = 100 * a + 10 * b + c;
  if(x % 4 == 0){
    cout << "YES";
  }else{
    cout << "NO";
  }
  return 0;
}