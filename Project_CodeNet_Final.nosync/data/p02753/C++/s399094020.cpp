#include<iostream>
using namespace std; 
string s;
int main() {
  getline(cin, s);

  if ((s == "AAA") || (s == "BBB")) {
    cout<<"No"<<endl;
  }
  else cout <<"Yes"<<endl;  
}