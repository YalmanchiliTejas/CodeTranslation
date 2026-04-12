#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9+7;

int main(){
  int H,W;
  cin >> H >> W;
  vector<string> A(H);
  for(int i=0;i<H;i++)  cin >> A.at(i);

  vector<vector<bool>> flag(H,vector<bool>(W,false));
  int y=0,x=0;
  for(;;){
    flag.at(y).at(x)=true;
    if(x+1<W && A.at(y).at(x+1)=='#') x++;
    else if(y+1<H && A.at(y+1).at(x)=='#')  y++;
    else break;
  }

  bool ans=true;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(A.at(i).at(j)=='#' && !flag.at(i).at(j)) ans=false;
    }
  }
  if(ans) cout << "Possible" << endl;
  else  cout << "Impossible" << endl;

  return 0;
}
