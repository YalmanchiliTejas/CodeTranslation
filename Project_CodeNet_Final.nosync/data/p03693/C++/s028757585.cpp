#include<bits/stdc++.h>
using namespace std;
int main(){
  int r, g, b, X;
  cin >> r >> g >> b;
  X = r*100+g*10+b;
  cout << ((X%4)?"NO":"YES") << endl;
}