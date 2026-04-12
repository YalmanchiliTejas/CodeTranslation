#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,s;
  cin >> a >> b >> c;
  
  s = a*100 + b*10 + c;
  if((s % 4) == 0){
    cout << "YES";
  }
  else cout << "NO";
  
  
}