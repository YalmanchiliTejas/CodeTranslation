#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W; cin >> H >> W;
  string A[10];
  for(int i=1; i<=H; i++){
    cin >> A[i];
    A[i]="."+A[i]+".";
  }
  string add="";
  for(int i=0; i<W+2; i++) add+=".";
  A[0]=A[H+1]=add;
  
  int px=1, py=1;
  while(!(px==W&&py==H)){
    if(A[py][px+1]=='#'&&A[py][px-1]=='.'&&
       A[py-1][px]=='.'&&A[py+1][px]=='.'){
      A[py][px]='.';
      px++;
    }else if(A[py][px+1]=='.'&&A[py][px-1]=='.'&&
       A[py-1][px]=='.'&&A[py+1][px]=='#'){
      A[py][px]='.';
      py++;
    }else{
      break;
    }
  }
  cout << ((px==W&&py==H&&A[py][px-1]=='.'&&
       A[py-1][px]=='.')?"Possible":"Impossible") << endl;
}