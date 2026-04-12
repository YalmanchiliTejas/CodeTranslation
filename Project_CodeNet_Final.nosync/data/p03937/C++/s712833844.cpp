#include <bits/stdc++.h>
using namespace std;

int main(){
  int flag=0,i,j,H,W,count=0;
  cin >> H >> W;
  char A[H][W];
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      cin >> A[i][j];
      if(A[i][j]=='#'){count++;}
    }
  }
  i=0;j=0;
  while(i<H || j<W){
  	if(i==H-1 && j==W-1){break;}
    if(A[i+1][j]=='#' && A[i][j+1]=='#'){
      flag=1;break;
    }else if(A[i+1][j]=='#'){
      i++;
    }else if(A[i][j+1]=='#'){
      j++;
    }else{
      flag=1;break;
    }
  }
  if(flag==0 && count==H+W-1){
    cout << "Possible" << endl;
  }else{
    cout << "Impossible" << endl;
  }
  return 0;
}
