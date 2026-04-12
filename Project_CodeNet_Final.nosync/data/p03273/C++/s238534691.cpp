#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  int c=0;
  cin>>h>>w;
  string s[h];
  for(int i=0;i<h;i++) cin>>s[i];
  for(int i=0;i<h;i++){
    int a=0;
    for(int j=0;j<w;j++){
      if(s[i].at(j)=='#')
        a++;
    }
    if(a==0){
      string t=s[i];
      for(int k=i-1;k>=0;k--){
        s[k+1]=s[k];
      }
      s[0]=t;
      c++;
    }
  }
  for(int i=w-1;i>=0;i--){
    int d=0;
    for(int j=0;j<h;j++){
      if(s[j].at(i)=='#')
        d++;
    }
    if(d==0){
      for(int l=0;l<h;l++)
        s[l].erase(i,1);
    }
  }
  for(int i=c;i<h;i++)
  cout<<s[i]<<endl;
}