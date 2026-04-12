#include<list>
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
string its(int n){
  stringstream s;
  s<<n;
  return s.str();
}
int main(){
  int i,k;
  int n,len;
  int y,m,d;
  string s;
  for(;;){
    cin>>n;
    if(n==0)
      break;
    list<int> t;
    for(i=0;i<n;i++){
      cin>>y>>m>>d;
      t.push_back((y<<9)|(m<<5)|d);
    }
    t.sort();
    list<int>::iterator it=t.begin();
    for(i=0;i<n;i++){
      s=its((*it)>>9);
      len=s.length();
      for(k=0;k<4-len;k++)
	cout<<"0";
      cout<<s<<" ";
      s=its(((*it)>>5)&0xF);
      len=s.length();
      for(k=0;k<2-len;k++)
	cout<<"0";
      cout<<s<<" ";
      s=its((*it)&0x1F);
      len=s.length();
      for(k=0;k<2-len;k++)
	cout<<"0";
      cout<<s<<endl;
      it++;
    }
  }
  return 0;
}