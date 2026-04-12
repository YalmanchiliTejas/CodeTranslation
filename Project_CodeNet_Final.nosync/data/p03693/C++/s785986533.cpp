#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C;
  cin >> A >> B >> C;
  int D;
  D=100*A+10*B+C;
  if(D%4==0){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}
