// Example program
#include <iostream>
#include <string>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int c=0;
  for(int i=0;i<s.size();i++){if(s[i]=='A')c++;}
  if(c==0 || c==3)cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}
