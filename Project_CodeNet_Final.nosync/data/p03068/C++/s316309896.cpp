#include <string>
#include <iostream>
using namespace std;
int main(){
  int a;cin>>a;
  string s;cin>>s;
  int k; cin >> k; k--;
  for(int i=0;i<a;i++) {
    if (s.at(i)!=s.at(k))
      cout << "*";
    else cout << s.at(i);
 }
 cout << endl;
  }
    