#include<bits/stdc++.h>
using namespace std;
int main() {
  int a,b;
  string c;
  char d,e;
  cin >> a;
    cin >> c;
  cin >> b;
  d = c[b-1];
  for (int i=0; i<a; i++) {
    e = c[i];
    if (e != d) {
      c[i] = '*';
    }
  }
  cout << c << endl;
}
 
  
