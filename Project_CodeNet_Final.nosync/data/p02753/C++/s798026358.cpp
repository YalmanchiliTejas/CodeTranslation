#include <bits/stdc++.h>
using namespace std;

void same(char x1,char x2,char x3){
  if (x1==x2&&x2==x3){
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
  return;
}

int main(){
  string S;
  cin >> S;
  char x1,x2,x3;
  x1=S.at(0);
  x2=S.at(1);
  x3=S.at(2);
  same(x1,x2,x3);
}
