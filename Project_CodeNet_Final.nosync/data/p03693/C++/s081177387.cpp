#include<iostream>
using namespace std;
int main(){
  int a,b,c,ans;
  cin >> a >> b >> c;
  ans = b*10+c;
  cout << ((ans%4==0) ? "YES":"NO") << endl;
}