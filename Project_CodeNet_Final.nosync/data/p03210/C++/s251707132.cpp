#include<iostream>
using namespace std;
int main(){
  int c;
  cin >> c;
  string ans = "NO";
  if(c == 3 || c == 5 || c == 7) ans = "YES";

  cout << ans;
}
