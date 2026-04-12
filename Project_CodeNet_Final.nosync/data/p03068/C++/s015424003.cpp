#include <iostream>
#include <string>
using namespace std;

int main() {
  int n,k;
  string s;
  char tmp;
  cin>>n>>s>>k;

  tmp=s[k-1];

  for(int i=0;i<n;i++){
    if(s[i]!=s[k-1]) s[i]='*';
  }
  cout<<s<<endl;
  return 0;
}