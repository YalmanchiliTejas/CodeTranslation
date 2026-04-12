#include<iostream>

using namespace std;

int main(){
  int h, w, hchk[109], wchk[109];cin >> h >> w;
  char a[109][109];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> a[i][j];
    }
  }
  for(int i=0;i<h;i++){
    bool tmp=true;
    for(int j=0;j<w;j++){
      if(a[i][j]=='#'){
        tmp=false;
        break;
      }
    }
    if(tmp)hchk[i]=1;
  }
  for(int i=0;i<w;i++){
    bool tmp=true;
    for(int j=0;j<h;j++){
      if(a[j][i]=='#'){
        tmp=false;
        break;
      }
    }
    if(tmp)wchk[i]=1;
  }
  for(int i=0;i<h;i++){
    if(hchk[i]==1)continue;
    for(int j=0;j<w;j++){
      if(wchk[j]==1)continue;
      cout << a[i][j];
    }
    cout << endl;
  }
}