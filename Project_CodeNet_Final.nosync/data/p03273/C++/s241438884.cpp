#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W; cin>>H>>W;
  vector<string> M(H);
  vector<int> yok(H,0);
  vector<int> tat(W,0);
  for(int i=0;i<H;i++){
    cin>>M[i];
    for(int j=0;j<W;j++){
      if(M[i][j]=='#'){
        yok[i]++; tat[j]++;
      }
    }
  }
  for(int i=0;i<H;i++){
    if(yok[i]){
      for(int j=0;j<W;j++){
        if(tat[j])
          cout<<M[i][j];
      }
      cout<<endl;
    }
  }
}