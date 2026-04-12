#include <bits/stdc++.h>
using namespace std;
int main(){
  int i,j,n;
  cin>>n;
  string s;
  vector<int> b(26);
  for(i=0;i<n;i++){
    cin>>s;
    vector<int> c(26);
    for(j=0;j<s.size();j++){
      if(i==0){
		b[(s[j]-'a')]++;
      }else{
		c[(s[j]-'a')]++;
      }
    }
    if(i!=0){
      for(j=0;j<26;j++){
		if(b[j]>c[j]){
			b[j]=c[j];
        }
      }
    }
  }
  for(i=0;i<26;i++){
    for(j=0;j<b[i];j++){
	  cout<<((char)('a'+i));
    }
  }
}