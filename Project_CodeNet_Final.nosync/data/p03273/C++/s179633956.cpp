#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  vector<string> a(H);
  for(int i=0;i<H;i++){
    cin >> a.at(i);
  }
  vector<bool> h(H,false);
  vector<bool> w(W,false);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(a[i][j]=='#'){
        h[i]=true;
        w[j]=true;
      }
    }
  }

  for(int i=0;i<H;i++){
    if(h[i]){
      for(int j=0;j<W;j++){
        if(w[j]){
          cout << a[i][j];
        }
      }
      cout<<endl;
    }
  }

  return 0;
}
