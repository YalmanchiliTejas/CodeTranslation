#include <bits/stdc++.h>
using namespace std;

int main()
{
  int h,w;
  cin >> h >> w;
  vector<bool> bh(h,0);
  vector<bool> bw(w,0);
  char a[h][w];
  
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      cin >> a[i][j];
      if(a[i][j]=='#'){
        bh.at(i)=1;
        bw.at(j)=1;
      }
    }
  }
  
  bool kaigyo=0;
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      if(bh.at(i)&&bw.at(j)){
        cout << a[i][j];
        kaigyo=1;
      }
    }
    if(kaigyo){
      cout << endl;
      kaigyo=0;
    }
  }
  
  return 0;
}