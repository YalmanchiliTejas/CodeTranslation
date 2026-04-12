#include<bits/stdc++.h>
using namespace std;
signed main(){
	int n,k;
  string s;
  cin>>n>>s>>k;
  for(int i=0;i<n;i++){
	if(s[k-1]!=s[i]){
      cout<<"*";
    }else{
      cout<<s[i];
    }
  }
  cout<<"\n";
}