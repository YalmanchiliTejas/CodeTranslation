#include<iostream>

#define rep(i,n) for(int i = 0; i < n; ++i)

using namespace std;

int main(void){
  string s;
  while(1){
    int cell[16][16]={0};
    int x, y, xx, yy;
    int W = -1, w=0;
    int d = 0;

    cin >> s;
    if(s[0] == '#')break;
    rep(i, s.size()){
      if(s[i] == '/'){
        d++;
        if(W == -1)W = w;
        w = 0;
      }else if(s[i] == 'b'){
        cell[d][w] = 1;
        w++;
      }else{
        w += s[i] - '0';
      }
    }
    d++;
    cin >> x >> y >> xx >> yy;
    x--;y--;xx--;yy--;

    int cnt = 1;
    
    cell[x][y] = 0;
    cell[xx][yy] = 1;

    rep(i, d){
      rep(j, W){
        if(cell[i][j] == 0){
          if( j + 1 < W && cell[i][j+1] == 0) cnt++;
          else{
            cout << cnt;
            cnt=1;
          }
        }else if( cell[i][j] == 1){
          cout << 'b';
        }
      }
      if(i != d-1)cout << '/';
    }
    cout << endl;
  }

  return 0;
}