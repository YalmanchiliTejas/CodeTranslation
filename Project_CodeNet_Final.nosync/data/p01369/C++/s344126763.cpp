#include <iostream>
#include <string>
using namespace std;
int main(){

  string st;
  int a,b,result,i;

  while(cin>>st){
    if(st[0]=='#') break;
  result=0;
  
  if(st[0]=='y'||st[0]=='u'||st[0]=='i'||st[0]=='o'||st[0]=='p'||st[0]=='h'||st[0]=='j'||st[0]=='k'||st[0]=='l'||st[0]=='n'||st[0]=='m') a=1;
  else a=0;

  for(i=1;i<st.size();i++){

    if(st[i]=='y'||st[i]=='u'||st[i]=='i'||st[i]=='o'||st[i]=='p'||st[i]=='h'||st[i]=='j'||st[i]=='k'||st[i]=='l'||st[i]=='n'||st[i]=='m') b=1;
    else b=0;

    if(a!=b) result++;
    a=b;

  }

  cout<<result<<endl;

  }

  return 0;

}