#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
int main(){
 string s;
 int i;
 cin >> s;
 rep(i,1){
 if(s[i]==s[i+1]&&s[i]==s[i+2]){
  cout << "No" << endl;
  return 0;
 }
 }
cout << "Yes" << endl;
return 0;
}