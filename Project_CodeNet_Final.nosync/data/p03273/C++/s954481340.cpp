#include<bits/stdc++.h>
using namespace std;
int main(void)
{
  int h,w,c1,i,j;
  cin>>h>>w;
  string a;
  string temp;
    
  for(i=0;i<h;i++){
    cin >> temp;
    a+=temp;
  }
  
  for(i=0;i<h;i++){
    c1=0;
    for(j=0;j<w;j++){
      if(a.at(i*w+j)=='#')break;
      c1++;
    }
    if(c1==w){
      for(j=0;j<w;j++){
        a.at(i*w+j)='s';
      }
    }
  }
  
  for(i=0;i<w;i++){
    c1=0;
    for(j=0;j<h;j++){
      if(a.at(i+j*w)=='#')break;
      c1++;
    }
    if(c1==h){
      for(j=0;j<h;j++){
        a.at(i+j*w)='s';
      }
    }
  }
  
  for(i=0;i<h;i++){
    c1=0;
    for(j=0;j<w;j++){
      if(a.at(i*w+j)!='s'){
      cout<<a.at(i*w+j);
      }
      else c1++;
    }
    if(c1!=w){
      cout<<endl;
    }
  }
}