#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  
  vector<char> g(H*W);
  int i;
  for(i=0;i<H*W;i++){
    cin >> g.at(i);
  }
  
  vector<int> y(H),x(W);
  for(i=0;i<H*W;i++){
    if(g.at(i) == '#'){
      y.at(i/W)+=1; x.at(i%W)+=1;
    } 
  }
  
  int j;
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      if(y.at(i)!=0 && x.at(j)!=0){
        cout << g.at(i*W+j);
      }  
    }    
    if(y.at(i)!=0){
      cout << endl;
    }
  }
}

