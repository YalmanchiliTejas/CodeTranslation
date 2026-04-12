#include <bits/stdc++.h>
using namespace std;

int main(){
  int H=0;
  int W=0;
  string S;
  cin>>H>>W;
  char p[H][W];
  for (int i=0;i<H;i++){
      cin>>S;
    for (int j=0;j<W;j++){
      p[i][j]=S.at(j);
    }
  }
  
  int tempi=0;
  int tempj=0;
  while(!((tempi==H-1)&&(tempj==W-1))){
    if(p[tempi+1][tempj]=='#'){
      p[tempi][tempj]='.';
      tempi++;
      continue;
    }
    if(p[tempi][tempj+1]=='#'){
      p[tempi][tempj]='.';
      tempj++;
      continue;
    }
    cout<<"Impossible"<<endl;
    return 0;
  }
  p[H-1][W-1]='.';

  for(int i=0;i<H;i++){
    for (int j=0;j<W;j++){
      if (p[i][j]=='#'){
        cout<<"Impossible"<<endl;
        return 0;
      }
    }
  }
  cout<<"Possible"<<endl;
  return 0;
}