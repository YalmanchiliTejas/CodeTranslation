#include<iostream>
#include<string>
using namespace std;
int main(){
  string s;
  string r="yuiophjklnm",l="qwertasdfgzxcvb";
  while(1){
    int c=0;
    cin>>s;
    if(s[0]=='#')break;
    bool f=0;
    for(int i=0;i<r.size();i++)if(s[0]==r[i])f=1;
    for(int i=1;i<s.size();i++){
      int f1=0;
      for(int j=0;j<r.size();j++)if(s[i]==r[j])f1=1;
      if(f!=f1)c++,f=f1;
    }
    cout<<c<<endl;
  }
  return 0;
}