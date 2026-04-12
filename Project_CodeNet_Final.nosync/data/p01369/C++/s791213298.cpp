#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int a,ans=0;
  while(1){
    ans=0;
    cin>>s;
    if(s=="#") break;
    for(int i=0;i<s.size();i++){
      if(i==0){
	if(s[i]=='y'||s[i]=='u'||s[i]=='i'||s[i]=='o'||s[i]=='p'||s[i]=='h'||s[i]=='j'||s[i]=='k'||s[i]=='l'||s[i]=='m'||s[i]=='n')  a=0;
	else a=1;
      }
      else if(a==1){
	if(s[i]=='y'||s[i]=='u'||s[i]=='i'||s[i]=='o'||s[i]=='p'||s[i]=='h'||s[i]=='j'||s[i]=='k'||s[i]=='l'||s[i]=='m'||s[i]=='n'){
	  ans++;
	  a=0;
	}
      }
      else if(a==0){
	if(s[i]!='y'&&s[i]!='u'&&s[i]!='i'&&s[i]!='o'&&s[i]!='p'&&s[i]!='h'&&s[i]!='j'&&s[i]!='k'&&s[i]!='l'&&s[i]!='m'&&s[i]!='n'){
	  ans++;
	  a=1;
	}
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}

