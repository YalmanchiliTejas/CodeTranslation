#include <iostream>
#include <string>
using namespace std;
int formula();
int digit();
int pls();
int p,result,cal;
string str;
char c;

int main(){
  cin>>str>>result;
  cal=str[0]-'0';
  for(int i=1;i<=(int)str.size();i++){
    if(i%2) c=str[i];
    else{
      if(c=='*') cal=cal*(str[i]-'0');
      else cal=cal+(str[i]-'0');
    }
  }
  p=0;
  int r=formula();
  if(cal==result&&r==result) cout<<'U'<<endl;
  else if(cal==result) cout<<'L'<<endl;
  else if(r==result) cout<<'M'<<endl;
  else cout<<'I'<<endl;
  return 0;
}

int formula(){
  int val=pls();
  while(str[p]=='+'){
    p++;
    val=val+pls();
  }
  return val;
}

int pls(){
  int val=digit();
  while(str[p]=='*'){
    p++;
    val=val*digit();
  }
  return val;
}

int digit(){
  int val=str[p]-'0';
  p++;
  return val;
}