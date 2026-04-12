#include<iostream>
#include<string>
using namespace std;

int main(){
  string s;
  int a,b,n,m = 0;
  cin >> s;
  for(int i = 0;i < s.size()-1;i++){
    if(s[i] == 'A' && s[i+1] == 'C')
      m = 1;
  }
  if(m == 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
