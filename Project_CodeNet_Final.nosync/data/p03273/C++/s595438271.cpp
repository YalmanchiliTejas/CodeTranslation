#include <bits/stdc++.h>
using namespace std;

void del(vector<vector<char>>&a,vector<int>&b,vector<int>&c){
  int h=a.size();
  int w=a.at(0).size();
  for (int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a.at(i).at(j)=='#'){
        b.at(i)=1;
        continue;
      }
    }
  }
    for (int i=0;i<w;i++){
    for(int j=0;j<h;j++){
      if(a.at(j).at(i)=='#'){
        c.at(i)=1;
        continue;
      }
    }
  }
}

int main(){
  int H,W;
  cin>>H>>W;
  vector<vector<char>>a(H,vector<char>(W));
  vector<int>h(H);
  vector<int>w(W);
  for(int i=0;i<H;i++)for(int j=0;j<W;j++)cin>>a.at(i).at(j);
  del(a,h,w);
  for(int i=0;i<H;i++){
    if(h.at(i)==0)continue;
    for(int j=0;j<W;j++){
      if(w.at(j)==0){
        if(j==W-1)cout<<endl;
        continue;
      }
      cout<<a.at(i).at(j);
      if(j==W-1)cout<<endl;
    }
  }
}
