#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int a, b;
  int s[5];
  while(1) {
    for(int i=0; i<5; i++) {
      cin >> a >> b;
      if(a+b == 0) return 0;
      
      s[i] = a+b;
    }
    int num;
    int temp=-987654321;
    for(int i=0; i<5; i++) {
      temp = max(temp, s[i]);
      if(s[i] == temp) num = i;
    }
    cout << (char)('A'+num) << " " << temp << endl;
  }
  
  return 0;
}