#include<bits/stdc++.h>
using namespace std;

int main(){
  string str;
  cin>>str;
  int bob;
  cin>>bob;
int ans=str[0]-'0';
 int f;

  for(int i=1;i<str.size();i++){
    if(str[i]=='+')f=1;
    else if(str[i]=='*')f=2;
    if(str[i]>='0' && str[i]<='9'){
      if(f==1) ans+=(str[i]-'0');
      else if(f==2)ans*=(str[i]-'0');
    }
  }
  char ansf='I';
   if(ans==bob)ansf='L';
    ans=0;
  for(int i=1;i<str.size();i++){
    int multi=0;
    if(str[i]=='*'){
      multi+=((str[i-1]-'0')*(str[i+1]-'0'));
      str[i-1]='0',str[i+1]='0';
      while(1){
	i++;
	if(i>=str.size()) break;
	if(str[i]=='*')multi*=(str[i+1]-'0'),str[i+1]='0';
	else if(str[i]=='+') break;
      }
    }
    ans+=multi;
  }
      for(int i=0;i<str.size();i++)
	if(str[i]>='0' && str[i]<='9')ans+=(str[i]-'0');
    if(ans==bob && ansf=='L') ansf='U';
  else if(ans==bob)ansf='M';
  cout<<ansf<<endl;
  return 0;
}