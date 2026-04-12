#include<iostream>
#include<string>
using namespace std;

int main()
{
  string left="qwertasdfgzxcvb";
  string right="yuiophjklnm";
  string s;
  int i,f,cnt;
  while(cin>>s,s!="#"){
    cnt=0;
    f=(left.find(s[0],0)!=string::npos)-(right.find(s[0],0)!=string::npos);
    for(i=0;i<s.size();i++){
      if(f!=((left.find(s[i],0)!=string::npos)-(right.find(s[i],0)!=string::npos))){
	f*=-1;
	cnt++;
      }
    }
    cout<<cnt<<endl;
  }
}