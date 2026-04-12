#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin >> h >> w;
  vector<string>a(h);
  int i,j;
  for(i=0;i<h;i++)cin>>a[i];
  bool chk = true;
  while(chk){
    chk=false;
    for(i=0;i<h;i++){
      bool tmp = true;
      for(j=0;j<w && tmp;j++){
        if(a[i][j]=='#')tmp=false;
      }
      if(tmp){
        a.erase(a.begin()+i);
        h--;
        chk = true;
      }
    }
    for(j=0;j<w;j++){
      bool tmp = true;
      for(i=0;i<h;i++){
        if(a[i][j]=='#')tmp=false;
      }
      if(tmp){
        for(i=0;i<h;i++)a[i].erase(a[i].begin()+j);
        w--;
        chk = true;
      }
    }
  }
  for(i=0;i<h;i++){
    for(j=0;j<w;j++)cout<<a[i][j];
    cout<<endl;
  }

}
