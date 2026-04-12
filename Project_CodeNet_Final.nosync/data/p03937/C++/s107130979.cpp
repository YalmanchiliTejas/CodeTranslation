#include<bits/stdc++.h>
using namespace std;

const int di[]={0,1};
const int dj[]={1,0};


int main(){
  int h,w,i,j;
  cin >> h >> w;
  vector<vector<char>> a(h,vector<char>(w));
  int n=0;
  for(i=0;i<h;++i){
    for(j=0;j<w;++j){
      cin >> a[i][j];
      if(a[i][j]=='#'){
        n++;
      }
    }
  }
  if(n==h+w-1){
    cout << "Possible" << endl;
  }else{
    cout << "Impossible" << endl;
  }
  return 0;
}
