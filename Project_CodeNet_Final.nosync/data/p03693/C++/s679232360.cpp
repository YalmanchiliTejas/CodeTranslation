#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C;
  cin >> A >> B >> C;
  int D;
  D = 10*B + C;
  if (D % 4 == 0){
  cout << "YES";
  }else{
  cout << "NO";
  }
}
