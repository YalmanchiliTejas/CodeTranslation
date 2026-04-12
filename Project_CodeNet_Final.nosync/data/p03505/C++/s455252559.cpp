#include <iostream>

using namespace std;

int main()
{
  long long int a, b, c;
  
  cin >> a >> b >> c;
  
  if (a <= b) {
    cout << 1 << endl;
    return (0);
  }
  if (b <= c) {
    cout << -1 << endl;
    return (0);
  }
  long long int div;
  
  if ((a-b) % (b-c) == 0) {
    div = (a-b) / (b-c);
  }
  else {
    div = 1 + (a-b) / (b-c);
  }
  
  cout << div*2 + 1 << endl;
}