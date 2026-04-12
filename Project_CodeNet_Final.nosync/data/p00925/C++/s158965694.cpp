#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
  int a[100],t;
  string s;
  cin>>s>>t;
  char b[100];
  a[0]=s[0]-'0';
  r(i,s.size()/2)a[i+1]=s[(i+1)*2]-'0';
  r(i,s.size()/2)b[i]=s[i*2+1];
  int p1=a[0],p2=0;
  r(i,s.size()/2)
    if(b[i]=='*')p1*=a[i+1];
    else p1+=a[i+1];
  r(i,s.size()/2)if(b[i]=='*')a[i+1]=a[i]*a[i+1],a[i]=0;
  r(i,s.size()/2+1)p2+=a[i];
  if(t==p1&&t==p2)cout<<'U'<<endl;
  else if(t!=p1&&t!=p2)cout<<'I'<<endl;
  else if(t!=p1&&t==p2)cout<<'M'<<endl;
  else cout<<'L'<<endl;
}