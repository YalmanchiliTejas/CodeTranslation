#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  vector<string> A(H);
  for(int i=0;i<H;i++){
    cin >> A.at(i);
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if((i!=0)&&(j!=0)){
        if((A.at(i-1).at(j)=='#')&&(A.at(i).at(j-1)=='#')){
          cout << "Impossible" << endl;
          return 0;
        }
      }
      if((i!=H-1)&&(j!=W-1)){
        if((A.at(i+1).at(j)=='#')&&(A.at(i).at(j+1)=='#')){
          cout << "Impossible" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Possible" << endl;
  return 0;
}
