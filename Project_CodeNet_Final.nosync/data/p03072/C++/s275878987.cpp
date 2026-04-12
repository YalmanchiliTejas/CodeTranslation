#include<iostream>
using namespace std;
 
int main() {
  int a, b[20], c, m;
  cin >> a;
  
  c=0;
  m=0;
  for(int i=0;i<a;i++) {
    cin >> b[i];
    //cout << i << " " << b[i] << endl;
    if (b[i]>=m) { m=b[i]; c++; }
  }
  cout << c;
  return 0;
}