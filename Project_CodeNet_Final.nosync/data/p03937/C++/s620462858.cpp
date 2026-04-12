#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,n=0;cin>>h>>w;
  vector<vector<char>>a(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>a.at(i).at(j);
      if(a.at(i).at(j)=='#')n++;
    }
  }
  if(n!=h+w-1)cout<<"Impossible"<<endl;
  else{
    vector<pair<int,int>>p(n);
    int s=0;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(a.at(i).at(j)=='#'){
          p.at(s).first=j;
          p.at(s).second=i;
          s++;
        }
      }
    }
    int t=0;
    for(int i=0;i<n-1;i++){
      if(p.at(i)>p.at(i+1)){
        t++;
        break;
      }
    }
    if(t>0)cout<<"Impossible"<<endl;
    else cout<<"Possible"<<endl;
  }
}