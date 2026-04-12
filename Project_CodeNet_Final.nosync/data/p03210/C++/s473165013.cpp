#include<iostream>
using namespace std;
int main(){
  int x;
  cin >> x;
  bool a;
  a = (x==3||x==5||x==7?true:false);
  if(a) cout << "YES" << endl;
  else cout << "NO" << endl;
}