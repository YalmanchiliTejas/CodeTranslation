#include<bits/stdc++.h>
using namespace std;
int main() {
 vector<char> s(100);
   for(int i=0; i<s.size(); i++) cin >> s.at(i);
  if(s.at(0) == s.at(1) && s.at(1) == s.at(2))
   cout << "No" << endl; 
  else  cout << "Yes" << endl; 
}