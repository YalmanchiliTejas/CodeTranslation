#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  string a = "No";
  cin >> s;
  for(int i = 0; i < 2; i++){
  	if(s.at(i) != s.at(i+1)){
    	a = "Yes";
    }
  }
  cout << a << endl;
}