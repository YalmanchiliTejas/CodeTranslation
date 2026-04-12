#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int H,W;
  cin >> H >> W;
  vector<string> v(H);
  for(int i = 0; i < H; i++) cin >> v[i];

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      bool flg1, flg2;
      // flg1: 下が#
      flg1 = (i+1<H && v[i+1][j] == '#');
      // flg2: 右が#
      flg2 = (j+1<W && v[i][j+1] == '#');

      if(flg1 && flg2){
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }
  cout << "Possible" << endl;
}
