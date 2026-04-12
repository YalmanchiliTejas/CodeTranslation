#include<bits/stdc++.h>
using namespace std;

int main() {
 string s;
  cin >> s;
  int a = 0,b = 0;
  for(auto i:s) {
  	if(i == 'A')
      a++;
    else 
      b++;
  }
  if(a!= 0 && b!=0)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  return 0;
}