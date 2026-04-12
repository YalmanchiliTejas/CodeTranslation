#include<iostream>

using namespace std;

int main(){
  int r,g,b;
  cin >> r >> g >> b;

  int T = 10*g+b;

  if(T%4 == 0)
    cout <<"YES\n";

  else
    cout <<"NO\n";
}
