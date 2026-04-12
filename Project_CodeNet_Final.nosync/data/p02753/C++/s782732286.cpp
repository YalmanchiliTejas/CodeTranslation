#include<iostream>
using namespace std;
int main(){
  
  int a=0,b=0;
  string s;
  cin>>s;
  for(int i=0; i<s.length(); i++){
  	if(s[i] == 'A') a++;
    else b++;
  }
  
  if(a==0 || b==0) cout<<"No\n";
  else cout<<"Yes\n";
return 0;
}