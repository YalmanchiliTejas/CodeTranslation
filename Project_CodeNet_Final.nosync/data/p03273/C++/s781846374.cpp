#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define COUNTOF1(array) (sizeof(array) / sizeof(array[0]))
#define COUNTOF2(array) (sizeof(array[0]) / sizeof(array[0][0]))

int main(){

  int H,W;
  cin >> H >> W;
  char a[H][W];
  // initialize
  vector<bool> h(H, false);
  vector<bool> w(W, false);

  rep(i,H){
    rep(j,W){
      cin >> a[i][j];
      if(a[i][j]=='#') {
        h[i]=true;
        w[j]=true;
      }
    }
  }

  rep(i,H){
    if(h[i]==true){
       rep(j,W){
         if(w[j]==true) cout << a[i][j];
       }
    cout << '\n';
    }
  }
}