#include<iostream>
#include<string>

using namespace std;

int main(){
  string s;
  cin >> s;
  if(s == "BBB" || s == "AAA") cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}