#include <iostream>
#include <vector>

using namespace std;

int main(){
  int H,W;
  cin>>H>>W;
  vector<vector<char> > a(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>a[i][j];
    }
  }

  vector<int> r(H,1),c(W,1);

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(a[i][j]=='#'){
        r[i]=0;
        c[j]=0;
      }
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if((r[i]==0)&&(c[j]==0)) cout<<a[i][j];
    }
    if(r[i]==0)cout<<endl;
  }

  return 0;
}

