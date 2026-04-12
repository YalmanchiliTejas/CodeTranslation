#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int i,f=0;
  cin >> s;
  
  for(i=0;i<2;i++){
    if(s.at(i)!=s.at(i+1))
      f++;
  }
  if(s.at(0)!=s.at(2))
    f++;
  
  if(f!=0)
    cout << "Yes" << endl;
  
  if(f==0)
    cout << "No" << endl;
}
