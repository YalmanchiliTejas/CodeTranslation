#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);//高速化、endlは使わない

  int N;

  cin >> N;

  if ((N==3) ||(N==5)||(N==7)) cout << "YES" << "\n";
  else cout << "NO" << "\n";
}
