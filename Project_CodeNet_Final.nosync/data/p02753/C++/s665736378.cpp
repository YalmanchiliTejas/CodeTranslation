#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

int main(void){
  int i,k[2]={};
  string s;
  
  cin >> s;
  
  for (i=0;i<3;i++) k[s[i]-'A']++;
  
  if (k[0]==0 || k[1]==0) cout << "No" << endl;
  else cout << "Yes" << endl;
  
  return 0;
}