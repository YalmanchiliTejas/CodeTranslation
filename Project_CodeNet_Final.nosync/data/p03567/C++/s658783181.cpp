#include <iostream>
using namespace std;
int main(){
  string s;
  cin >> s;
  string keka = "No";
  for(int i = 0; s.size()-1 > i; i++){
    if(s[i] == 'A' && s[i+1] == 'C')keka="Yes";
  }
  cout << keka << endl;
}