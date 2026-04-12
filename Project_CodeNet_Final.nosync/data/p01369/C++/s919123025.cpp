#include <iostream>
#include <string>
using namespace std;

int main(){
  string s,l,ss="#";
  int a,now,nnow,cou;
  l="qwertasdfgzxcvb";
  while(1){
    cin>>s;
    if(s==ss)break;
    a=s.size();
    if(l.find(s[0])==-1)now=0;
    else now=1;
    cou=0;
    for(int i=1;i<a;i++){//最後まで
      if(l.find(s[i])==-1)nnow=0;
      else nnow=1;
      if(now!=nnow){
	cou++;
	now=nnow;
      }
    }
    cout << cou << endl;
  }
  return 0;
}