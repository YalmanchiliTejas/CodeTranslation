#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a = 0;
  int b = 0;
  string p;
  cin >> p;
  for(int i = 0; i < 3; i++){
    if(p.at(i) == 'A'){
      a++;}
    if(p.at(i) == 'B'){
      b++;}
  }
  if(a > 0 && b > 0){
    cout << "Yes" << endl;}
  else{
    cout << "No"  << endl;}
}
