#include "bits/stdc++.h"
using namespace std;

int main(){
  int h,w;
  cin>>h>>w;
  vector<string> a(h);
  for(int i=0;i<h;i++)cin>>a[i];

  vector<int> t(h,1);
  for(int i=0;i<h;i++){
    int f=0;
    for(int j=0;j<w;j++){
      if(a[i][j]=='#')f=1;
    }
    if(f==0)t[i]=0;
  }

  vector<int> y(w,1);
  for(int i=0;i<w;i++){
    int f=0;
    for(int j=0;j<h;j++){
      if(a[j][i]=='#')f=1;
    }
    if(f==0)y[i]=0;
  }

  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(t[i]&&y[j])cout<<a[i][j];
    }
    if(t[i])cout<<endl;
  }

}
