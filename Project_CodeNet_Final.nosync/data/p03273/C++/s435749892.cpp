#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<string> M(H);
  vector<bool> b(H);
  char c='.';
  
  for(int i=0; i<H; i++){
    int count=0;
    b.at(i)=1;
    cin >> M.at(i);
    for(int j=0; j<W; j++){
      if(M.at(i).at(j)==c){
        count++;
      }
    }
    if(count == W){
      b.at(i)=0;
      for (int k=0; k<W; k++){
        M.at(i).at(k)='x';
      }
    }
  }
  for(int i=0; i<W; i++){
    int count=0;
    for(int j=0; j<H ; j++){
      if(M.at(j).at(i)==c || M.at(j).at(i)=='x'){
        count++;
      }
    }
    if(count == H){
      for(int k=0; k<H; k++){
        M.at(k).at(i)='x';
      }
    }
  }
      
  
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if( M.at(i).at(j)!='x'){
        cout << M.at(i).at(j);
      }
    }
    if(b.at(i)){
      cout << endl;
    }
  }
  
 
  
  return 0;
}