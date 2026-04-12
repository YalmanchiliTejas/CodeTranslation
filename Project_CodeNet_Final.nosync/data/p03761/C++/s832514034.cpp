#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
  int n,i,j,k,cn,cn2;
  cin >> n;
  string s[n];
  char x,y;
  for(i=0;i<n;i++)cin >> s[i];
  for(i=0;i<n;i++)sort(s[i].begin(),s[i].end());
  for(x='a';x<='z';x++){
    cn = 346;
    for(i=0;i<n;i++){
      cn2 = 0;
      for(j=0;j<s[i].size();j++){
        if(s[i][j]==x)cn2++;
      }
      cn = min(cn,cn2);
    }
    for(i=0;i<cn;i++)cout << x;
  }
  cout << endl;
  return 0;
}
