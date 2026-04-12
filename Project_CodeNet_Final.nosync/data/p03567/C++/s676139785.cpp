#include<iostream>
#include<string>

using namespace std;
int main(){
  string s;
  cin >> s;
  if(s.find("AC")!=string::npos)
    cout << "Yes" << "\n";
  else
    cout << "No" << "\n";
  return 0;
}
