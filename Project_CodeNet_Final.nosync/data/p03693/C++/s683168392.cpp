#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int N;
  N=100*a+10*b+c;
  if(N%4==0) cout << "YES" << endl;
  else cout << "NO" << endl;
}