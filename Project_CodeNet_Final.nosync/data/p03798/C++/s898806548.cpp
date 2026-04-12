#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main(){
  int n;
  string s;
  cin>>n>>s;
  string ans;
  for(int bits=0; bits<4; bits++){
    ans="";
    if(bits&1) ans+='W';
    else ans+='S';
    if(bits&2) ans+='W';
    else ans+='S';
    for(int i=2; i<n; i++){
      if(s[i-1]=='o'&&ans[i-1]=='S'){
	ans+=ans[i-2];
      }
      else if(s[i-1]=='o'&&ans[i-1]=='W'){
	if(ans[i-2]=='W') ans+='S';
	else ans+='W';
      }
      else if(s[i-1]=='x'&&ans[i-1]=='S'){
	if(ans[i-2]=='W') ans+='S';
	else ans+='W';
      }
      else{
	ans+=ans[i-2];
      }
    }
    bool f1=false,f2=false;
    if(s[n-1]=='o'&&ans[n-1]=='S'){
      if(ans[n-2]==ans[0]){
	f1=true;
      }
    }
    else if(s[n-1]=='o'&&ans[n-1]=='W'){
      if(ans[n-2]!=ans[0]){
	f1=true;
      }
    }
    else if(s[n-1]=='x'&&ans[n-1]=='S'){
      if(ans[n-2]!=ans[0]){
	f1=true;
      }
    }
    else{
      if(ans[n-2]==ans[0]){
	f1=true;
      }
    }
    if(s[0]=='o'&&ans[0]=='S'){
      if(ans[n-1]==ans[1]){
	f2=true;
      }
    }
    else if(s[0]=='o'&&ans[0]=='W'){
      if(ans[n-1]!=ans[1]){
	f2=true;
      }
    }
    else if(s[0]=='x'&&ans[0]=='S'){
      if(ans[n-1]!=ans[1]){
	f2=true;
      }
    }
    else{
      if(ans[n-1]==ans[1]){
	f2=true;
      }
    }
    if(f1&&f2){
      cout<<ans<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
}


