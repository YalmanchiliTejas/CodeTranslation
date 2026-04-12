#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define BIG 1000000010
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
typedef long long int ll;

int main(){
  string s;
  cin>>s;
  int m=0,l=0,n,nn;
  cin>>nn;
  stack<int>q;
  q.push(s[0]-'0');
  for(int i=1;i<s.size();i+=2){
    if(s[i]=='*'){
      n=q.top();
      q.pop();
      q.push(n*(s[i+1]-'0'));
    }
    else{
      q.push(s[i+1]-'0');
    }
  }
  while(!q.empty()){
    n=q.top();
    m+=n;
    q.pop();
  }
  q.push(s[0]-'0');
  for(int i=1;i<s.size();i+=2){
    if(s[i]=='*'){
      n=q.top();
      q.pop();
      q.push(n*(s[i+1]-'0'));
    }
    else{
      n=q.top();
      q.pop();
      q.push(n+(s[i+1]-'0'));
    }
  }
  l=q.top();
  if(nn==m){
    if(nn==l) cout<<'U'<<endl;
    else cout<<'M'<<endl;
  }
  else{
    if(nn==l) cout<<'L'<<endl;
    else cout<<'I'<<endl;
  }
    
  return 0;
}

