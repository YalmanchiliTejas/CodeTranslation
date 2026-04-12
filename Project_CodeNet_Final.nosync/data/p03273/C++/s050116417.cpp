#include<bits/stdc++.h>
using namespace std;
#define rt(i,n) for(int i=0;i<n;i++)
int main(){
  int h,w;cin>>h>>w;
  vector<string>a(1);
  cin>>a.at(0);
  if(h>1){
    rt(i,h-1){
      string s;cin>>s;
      int p=0;
      rt(j,w){if(s.at(j)=='#')p++;}
      if(p>0)a.push_back(s);
    }
  }
  h=a.size();
  int i=0;
  while(i<a.at(0).size()){
    int p=0;
    rt(j,h){if(a.at(j).at(i)=='#')p++;}
    if(p==0){
      rt(j,h)a.at(j)=a.at(j).erase(i,1);
      i--;
    }
    w=a.at(0).size();
    i++;
  }
  int k=0;
  rt(i,w){if(a.at(0).at(i)=='#')k++;}
  if(k>0){
    rt(i,h)cout<<a.at(i)<<endl;
  }
  else{
    for(int i=1;i<h;i++)cout<<a.at(i)<<endl;
  }
}
