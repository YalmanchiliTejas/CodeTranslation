#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int H,W;
  cin >> H >> W;
  vector<string> A(H);
  for(int i=0;i<H;i++){
    cin >> A[i];
  }
  set<int> Hset,Wset;
  for(int i=0;i<H;i++){
    bool flag=true;
    for(int j=0;j<W;j++){
      if(A[i][j]=='#'){
        flag=false;
        break;
      }
    }
    if(flag){
      Hset.insert(i);
    }
  }
  for(int i=0;i<W;i++){
    bool flag=true;
    for(int j=0;j<H;j++){
      if(A[j][i]=='#'){
        flag=false;
        break;
      }
    }
    if(flag){
      Wset.insert(i);
    }
  }
  for(int i=0;i<H;i++){
    if(Hset.count(i)){
      continue;
    }
    for(int j=0;j<W;j++){
      if(Wset.count(j)){
        continue;
      }
      cout << A[i][j];
    }
    cout << endl;
  }
}