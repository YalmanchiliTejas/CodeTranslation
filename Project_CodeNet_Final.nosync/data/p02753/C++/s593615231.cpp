#include<iostream>
#include<string>
using namespace std;
int main(){
  string s;
  cin >> s;
  if(s == "AAA" || s == "BBB"){
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
}