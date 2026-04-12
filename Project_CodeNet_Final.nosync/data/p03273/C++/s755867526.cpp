#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<string> masu(H);
  for (int i=0;i<H;i++){
    cin>>masu.at(i);
  }

  vector<int> H_kuro(H,0);
  vector<int> W_kuro(W,0);

  for (int i = 0;i<H;i++){
    for (int j = 0;j<W;j++){
      if(masu.at(i).at(j)=='#'){
        H_kuro.at(i)=1;
        W_kuro.at(j)=1;
      }
    }
  }

  for (int i = 0;i<H;i++){
    for (int j = 0;j<W;j++){
      if(H_kuro.at(i)==1 && W_kuro.at(j)==1){
        cout<<masu.at(i).at(j);
      }
      if(H_kuro.at(i)==1 && j==W-1){
        cout<<endl;
      }
    }
  }
}
