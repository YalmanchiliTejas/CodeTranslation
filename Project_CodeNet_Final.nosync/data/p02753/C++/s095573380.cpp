#include <bits/stdc++.h>
using namespace std;


int main() {
  string s;

  cin >> s;

  set<char> station;

  for(int i=0; i<s.size(); i++){
    station.insert(s.at(i));
    
  }
  
  if(station.size() == 2)
    cout << "Yes";
  else
    cout << "No";
   
}