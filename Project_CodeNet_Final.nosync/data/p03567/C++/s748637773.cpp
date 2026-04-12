#include <bits/stdc++.h>
using namespace std;
int main(){
  string s,c = "No";
  cin >> s;
  for(int i=0;i<s.size()-1;i++){
    if(s[i]=='A'&&s[i+1]=='C') c = "Yes";
  }
  cout << c << endl;
}
