#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  char A[W][H];
  int cnt=0;
  int i, j, k;
  for(j=0; j<H; j++){
    for(i=0; i<W; i++){
      cin >> A[i][j];
      if(A[i][j]=='#') cnt++;
    }
  }
  if(cnt == H+W-1){
    cout << "Possible" << endl;
  }
  else cout << "Impossible" << endl;
  return 0;
}