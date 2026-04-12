#include<bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<string> A(H);
  for(int i=0; i<H; i++){
    cin >> A.at(i);
  }
  vector<int> P(W+H-1, 0);
  for(int i=0; i<W; i++){
    for(int j=0; j<H; j++){
      if(A.at(j).at(i)=='#'){
        P.at(i+j)++;
      }
    }
  }
  int Ans=1;
  for(int i=0; i<W+H-1; i++){
    if(P.at(i)!=1){
      Ans=0;
    }
  }
  if(Ans==1){
    cout << "Possible" << endl;
  }
  else{
    cout << "Impossible" << endl;
  }
}