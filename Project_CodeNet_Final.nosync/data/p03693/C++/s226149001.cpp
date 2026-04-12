#include<iostream>
using namespace std;
int main(){
  string a,b,c;
  cin >> a >> b >> c;
  string num = a + b + c;
  int N = stoi(num,nullptr,10);
  if(N%4 == 0)
    cout << "YES" << "\n";
  else
    cout << "NO" << "\n";
  return 0;
}
