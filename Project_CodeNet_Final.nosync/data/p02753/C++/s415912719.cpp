#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  string s;
  cin>>s;
  if(s[1] == s[2] && s[0] == s[1])
  cout<<"No"<<endl;
  else
    cout<<"Yes"<<endl;
  return 0;
}