#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

int h, w;
char a[10][10];

int main(){
  cin >> h >> w;
  int cnt = 0;
  rep(i, h){
    rep(j, w){
      cin >> a[i][j];
      if(a[i][j] == '#'){
        cnt++;
      }
    }
  }
  if(cnt == h + w - 1){
    cout << "Possible"<< endl;
  }else{
    cout << "Impossible" << endl;
  }
}
