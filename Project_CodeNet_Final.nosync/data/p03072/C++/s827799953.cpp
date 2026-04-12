#include <iostream>

using namespace std;

int main() {

  unsigned long long a, b, c = 0, d = 0;
  cin >> a;
  for(int i = 1;i <= a;i++){
    cin >> b;
    if(c <= b){
      d++;
      c = b;
    }
  }
  cout << d;
  return 0;
}
