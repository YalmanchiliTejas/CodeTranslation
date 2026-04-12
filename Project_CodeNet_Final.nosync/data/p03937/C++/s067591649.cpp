#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
  int H,W;
  bool f=true;
  cin>>H>>W;
  char c[H][W];

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++) cin>>c[i][j];
  }

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      int ax=j+1,ay=i-1,bx=j-1,by=i+1;
      if(c[i][j]=='#'){
        if(0<=ax&&ax<W&&0<=ay&&ay<H&&c[ay][ax]=='#') f=false;
        if(0<=bx&&bx<W&&0<=by&&by<H&&c[by][bx]=='#') f=false;
      }
    }
  }
  if(f) cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
}
