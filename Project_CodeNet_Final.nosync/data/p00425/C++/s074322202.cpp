#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)

enum {migi, hidari, mae, ushiro, ccw, cw};
int dx[] = {0,0,1,-1,0,0};
int dy[] = {1,-1,0,0,0,0};
int op[6][6] = {
    {4,1,0,3,5,2},
    {2,1,5,3,0,4},
    {3,0,2,5,4,1},
    {1,5,2,0,4,3},
    {0,4,1,2,3,5},
    {0,2,3,4,1,5},
};
void roll(vector<int> &v, int dir){
  vector<int> temp = v;
  for(int i = 0; i < 6; i++){
      temp[i] = v[op[dir][i]];
  }
  v = temp;
}
vector<int> dice[24];

void init_dice(){
  for(int i=1; i < 24; i++){
      dice[i] = dice[i-1];
      roll(dice[i], ccw);
      if( i % 8 == 0 ) roll(dice[i], hidari);
      else if(i % 4 == 0) roll(dice[i], mae);
  }
}


int main() {
  for (int N; cin >> N, N; ) {
      vector<int> v;
      v.push_back(1);
      v.push_back(2);
      v.push_back(3);
      v.push_back(5);
      v.push_back(4);
      v.push_back(6);

      int ans = 1;
      REP(i, N) {
          string op; cin >> op;
          int dir = 0;
          switch (op[0]) {
          case 'N': dir = ushiro; break;
          case 'S': dir = mae; break;
          case 'E': dir = migi; break;
          case 'W': dir = hidari; break;
          case 'R': dir = cw; break;
          case 'L': dir = ccw; break;
          }
          roll(v, dir);
          ans += v[0];
      }
      cout << ans << endl;
  }
  return 0;
}