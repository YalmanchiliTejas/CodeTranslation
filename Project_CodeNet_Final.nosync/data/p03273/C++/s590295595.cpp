#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1000000000000000000

using namespace std;

int main(void){
  ll h, w;
  cin >> h >> w;
  
  vector<string> a(h);
  for (int i = 0; i < h; i++){
    cin >> a[i];
  }


  for (int i = 0; i < 201; i++){
    for (int j = 0; j < h; j++){
      int ok = 1;
      for (int k = 0; k < w; k++){
        if (a[j][k] == '#')
          ok = 0;
      }
      if (ok){
        h--;
        for (int k = j; k < h; k++){
          a[k] = a[k+1];
        }
      }
    }

    for (int j = 0; j < w; j++){
      int ok = 1;
      for (int k = 0; k < h; k++){
        if (a[k][j] == '#')
          ok = 0;
      }
      if (ok){
        w--;
        for (int k = j; k < w; k++){
          for (int l = 0; l < h; l++){
            a[l][k] = a[l][k+1];
          }
        }
      }
    }
  }


  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cout << a[i][j];
    }
    cout << endl;
  }

  return 0;
}
