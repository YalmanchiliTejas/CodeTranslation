#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<char>> T(H,vector<char>(W));
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++) cin >> T[i][j];
  }
  int count=0,k_c=0;
  vector<bool> Hc(W,false),Wc(H,false);
  
  for(int i=0;i<H;i++){
    count = 0;
    for(int j=0;j<W;j++){
      if(i==0){
        k_c = count;
        count = 0;
        for(int k=0;k<H;k++)if(T[k][j] == '.')count++;
        if(count == H)Hc[j]=true;
        count=k_c;
      }
      if(T[i][j]=='.')count++;
    }
    if(count == W)Wc[i]=true;
  }
  
  for(int i=0;i<H;i++){
    if(Wc[i])continue;
    for(int j=0;j<W;j++){
      if(Hc[j])continue;
      cout << T[i][j];
    }
    cout << endl;
  }
  
  return 0;
}


