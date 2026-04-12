#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >>h>>w;
  char a[h][w];
  bool hantei[h];
  bool hantei2[w];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>a[i][j];
    }
  }
  for(int i=0;i<h;i++){
    bool check=false;
    for(int j=0;j<w;j++){
      if(a[i][j]=='.')check=true;
      else {
        check=false;
        break;
      }
    }
    if(check==true)hantei[i]=true;
    else hantei[i]=false;
  }
  for(int j=0;j<w;j++){
    bool check=false;
    for(int i=0;i<h;i++){
      if(a[i][j]=='.')check=true;
      else {
        check=false;
        break;
      }
    }
    if(check==true)hantei2[j]=true;
    else hantei2[j]=false;
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(hantei[i]==false&&hantei2[j]==false)cout<<a[i][j];
    }
    if(hantei[i]==false)cout<<endl;
  }
  return 0;
}
