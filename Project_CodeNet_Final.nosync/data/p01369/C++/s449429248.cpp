#include<iostream>
#include<string>
using namespace std;

int main(){
  int ans;
  string s1="qwertasdfgzxcvb";
  string s2="yuiophjklnm";
  string s;

  while(1){
    cin>>s;
    ans=0;
    if(s[0]=='#')break;
    int flag=0;
    for(int i=0;i<(int)s.size();i++){
      for(int j=0;j<(int)s1.size();j++){
	if(s[i]==s1[j]){
	  if(flag==0||flag==2){
	    ans++;
	    flag=1;
	  }
	}
      }
      for(int j=0;j<(int)s2.size();j++){
	if(s[i]==s2[j]){
	  if(flag==0||flag==1){
	    ans++;
	    flag=2;
	  }
	}
      }
    }
    cout<<ans-1<<endl;
    s.clear();
  }
  return 0;
}