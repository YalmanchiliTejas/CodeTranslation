#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 1;i<=n;++i)
typedef long long ll;
 
int main(){
  int h,w;
  cin >> h >> w;
  char A[h][w];
  int count = 0;
  rep(i,h){
    rep(j,w){
      cin >> A[i][j];
      if(A[i][j] == '#'){
        ++count;
      }      
    }
  }
  if(count != h+w-1){
    cout << "Impossible" << endl;
    return 0;
  }
  else{
    rep(i,h){
      rep(j,w){
        if(i < h && j < w){
          if(A[i][j] == '#'){
            if(A[i+1][j] == '#' && A[i][j+1] == '#'){
              cout << "Impossible" << endl;
              return 0;
            }
            if(A[i+1][j] == '.' && A[i][j+1] == '.'){
              cout << "Impossible" << endl;
              return 0;
            }
         }
         if(i == h && j < w){
           if(A[i][j] == '#' && A[i][j+1] == '.'){
             cout << "Impossible" << endl;
             return 0;
           }
         }
         if(i < h && j == w){
           if(A[i][j] == '#' && A[i+1][j] == '.'){
             cout << "Impossible" << endl;
             return 0;
           }
         } 
      }
    }
  }
}
  cout << "Possible" << endl;
  return 0;
}
