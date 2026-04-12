#include<iostream>
using namespace std;
int A, B, C;
int main(){
  cin >> A >> B >> C;
  if((A*100 + B*10 + C) % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}