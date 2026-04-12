#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  string s;
  cin >> s;
  int n=s.size();
  int k;
  cin >> k;
  int ans=0;
  if(n>1){
    if(k==1){
      ans=ans+(n-1)*9;
    }
    else if(k==2){
      ans=ans+(n-1)*(n-2)/2*81;
    }
    else{
      ans=ans+(n-1)*(n-2)*(n-3)/6*729;
    }
  }
  if(k==1){
    ans+=(s[0]-'0');
  }
  if(k==2){
    ans+=(s[0]-'1')*(n-1)*9;
    s.erase(0,1);
    n--;
    while(s[0]=='0'){
      s.erase(0,1);
      n--;
    }
    if(n>=1){
      ans=ans+(n-1)*9;
      ans+=(s[0]-'0');
    }  
  }
  if(k==3){
    ans+=(s[0]-'1')*(n-1)*(n-2)/2*81;
    s.erase(0,1);
    n--;
    while(s[0]=='0'){
      s.erase(0,1);
      n--;
    }
    if(n>1){
      ans=ans+(n-1)*(n-2)/2*81;
      ans+=(s[0]-'1')*(n-1)*9;
    s.erase(0,1);
    n--;
    while(s[0]=='0'){
      s.erase(0,1);
      n--;
    }
    if(n>=1){
      ans=ans+(n-1)*9;
      ans+=(s[0]-'0');
    } 
    }
  }
  cout << ans << endl;
}