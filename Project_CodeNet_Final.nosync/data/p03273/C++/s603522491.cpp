#include<bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for(int i=0; i<H; i++){
    cin >> S.at(i);
  }
  set<int> AnsH, AnsW;
  for(int i=0; i<H; i++){
    int Ans=1;
    for(int j=0; j<W; j++){
      if(S.at(i).at(j)=='#'){
        Ans=0;
        break;
      }
    }
    if(Ans==1){
      AnsH.insert(i);
    }
  }
  for(int i=0; i<W; i++){
    int Ans=1;
    for(int j=0; j<H; j++){
      if(S.at(j).at(i)=='#'){
        Ans=0;
        break;
      }
    }
    if(Ans==1){
      AnsW.insert(i);
    }
  }
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(AnsH.count(i)==0 && AnsW.count(j)==0){
        cout << S.at(i).at(j);
      }
    }
    if(AnsH.count(i)==0){
      cout << endl;
    }
  }
}