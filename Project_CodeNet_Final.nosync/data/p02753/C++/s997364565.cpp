#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  string a,b,c;
  a=S.at(0);
  b=S.at(1);
  c=S.at(2);

  if (a==b && b==c){
    cout << "No" <<endl;
  }
  else{
    cout << "Yes" <<endl;
  }
}