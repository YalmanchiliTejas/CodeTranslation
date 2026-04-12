#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int a, b;
  a = b = 0;
  for(int i = 0; i < 3; ++i){
    if(s[i]=='A')a++;
    if(s[i]=='B')b++;
  }
  if(a&&b)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
