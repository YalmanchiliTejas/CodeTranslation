#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char a[10][10];

int main(){
  int h, w;
  cin >> h >> w;
  for(int i = 1 ; i <= h ; i++){
    for(int j = 1 ; j <= w ; j++){
      cin >> a[i][j];
    }
  }
  for(int i = 1 ; i <= h ; i++){
    for(int j = 1 ; j <= w ; j++){
      for(int x = 1 ; x < i ; x++){
        for(int y = j+1 ; y <= w ; y++){
          if(a[i][j]=='#'&&a[x][y]=='#'){
            cout << "Impossible";
            return 0;
          }
        }
      }
    }
  }
  cout << "Possible";
}
