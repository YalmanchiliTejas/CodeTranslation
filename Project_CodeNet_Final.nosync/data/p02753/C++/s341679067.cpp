#include<iostream>
using namespace std;
int main() {
  string s;
  cin >> s;
  int c = s[0];
  if(c!=s[1]){
    cout << "Yes";
  }else if (c!=s[2]){
    cout << "Yes";
  }else{
    cout << "No";
  }
}
