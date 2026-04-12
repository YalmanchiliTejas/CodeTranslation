#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin>>h>>w;
  vector<vector<char>> vec(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>vec[i][j];
    }
  }
  vector<bool> H(h),W(w);
   for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(vec[i][j]=='#')H[i]=W[j]=true;
    }
   }
  for(int i=0;i<h;i++){
    if(!H[i])continue;
    for(int j=0;j<w;j++){
      if(!W[j])continue;
      cout<<vec[i][j];
    }
    cout<<endl;
  }
}