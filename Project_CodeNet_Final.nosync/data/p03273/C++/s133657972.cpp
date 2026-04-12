#include <bits/stdc++.h>
#define inf 1000000000
#define maxs(x,y) (x = max(x , y))
#define mins(x,y) (x = min(x , y))
using namespace std;
typedef long long int ll;

int main(){

  int H,W,i,j;
  cin >> H >> W ;
  char a[H][W];
  bool x[H]={false};
  bool y[W]={false};

  for(i=0 ; i<H ; i++){
    for(j=0 ; j<W ; j++){
      cin >> a[i][j];
      if(a[i][j] == '#'){
        x[i] = true;
        y[j] = true;
      }
    }
  }

  for(i=0 ; i<H ; i++){
    if(!x[i]){
      continue;
    }
    for(j=0 ; j<W ; j++){
      if(!y[j]){
        continue;
      }
      cout << a[i][j];
    } 
    cout << "\n"; 
  }
}
