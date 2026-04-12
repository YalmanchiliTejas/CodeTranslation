#include<iostream>
using namespace std;
enum{W=10,H=10};

bool clear(bool field[H][W]){
  bool ok=true;
  for(int i=0;i<H;i++)for(int j=0;j<W;j++)if(field[i][j])ok=false;
  return ok;
}

int main(){
  int n;
  bool field[H][W];
  bool dup[H][W];
  int bit[H];
  cin>>n;
  int t=0;
  while(n-->0){
    for(int i=0;i<H;i++)for(int j=0;j<W;j++)cin>>field[i][j];

    for(bit[0]=0; bit[0] < (1<<10); bit[0]++){
      for(int i=1;i<H;i++)bit[i]=0;
      for(int i=0;i<H;i++)for(int j=0;j<W;j++)dup[i][j]=field[i][j];

      for(int j=0;j<W;j++){
        if(!((bit[0]>>j)&1))continue;
        dup[0][j]^=1;
        dup[1][j]^=1;
        if(j>0)dup[0][j-1]^=1;
        if(j<W-1)dup[0][j+1]^=1;
      }

      for(int i=1;i<H;i++){
        for(int j=0;j<W;j++){
          if(dup[i-1][j]){
            bit[i]^=(1<<j);
            dup[i][j]^=1;
            dup[i-1][j]^=1;
            if(i<H-1)dup[i+1][j]^=1;
            if(j>0)dup[i][j-1]^=1;
            if(j<W-1)dup[i][j+1]^=1;
          }
        }
      }
      if(clear(dup))break;
    }
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        if(j!=0)cout<<" ";
        if(bit[i]&(1<<j))cout<<"1";
        else cout<<"0";
      }
      cout<<endl;
    }
  }
}