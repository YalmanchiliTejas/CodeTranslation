#include <bits/stdc++.h>
using namespace std;

template<typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}

signed main(){
  int h,w;cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++)cin>>s[i];
  int nowy=0,nowx=0;
  while(nowy!=h-1||nowx!=w-1){
    if(nowy<h-1&&s[nowy+1][nowx]=='#')s[nowy++][nowx]='A';
    else if(nowx<w-1&&s[nowy][nowx+1]=='#')s[nowy][nowx++]='A';
    else fin("Impossible");
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if((i<h-1||j<w-1)&&s[i][j]=='#')fin("Impossible");
    }
  }
  fin("Possible");
}
