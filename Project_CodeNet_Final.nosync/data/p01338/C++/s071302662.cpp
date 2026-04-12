#include<iostream>
using namespace std;

int board[5][5];
int dp[6][4][4][4][4];
int score[4] = {0, 60, 70, 80};
const int inf = 1000000000;


int power(int s,int push) {
  if(s == 0) return 0;
  s--;
  int ps = (s + push) % 4;
  return score[ps];
}

int main() {
  int n;
  cin>>n;

  while(n--) {
    for(int i=0; i<5; ++i) {
      for(int j=0; j<5; ++j) {
    cin>>board[i][j];
      }
    }

    for(int i=0; i<6; ++i)
      for(int j=0; j<4; ++j)
    for(int k=0; k<4; ++k)
      for(int l=0; l<4; ++l)
        for(int m=0; m<4; ++m) {
          if(i) dp[i][j][k][l][m] = 0;
          else dp[i][j][k][l][m] = -inf;
        }
    dp[0][0][0][0][0] = 0;

    for(int i=1; i<6; ++i) {
      for(int x1=0; x1<=3; ++x1)
    for(int x2=0; x2<=3; ++x2)
      for(int x3=0; x3<=3; ++x3)
        for(int x4=0; x4<=3; ++x4) {
          int m = 0;
          for(int u1=0; u1<=3; ++u1)
        for(int u2=0; u2<=3; ++u2)
          for(int u3=0; u3<=3; ++u3)
            for(int u4=0; u4<=3; ++u4) {
              int mt = 0;
              mt += power(board[i-1][0], x1+u1);
              mt += power(board[i-1][1], x1+x2+u1+u2);
              mt += power(board[i-1][2], x2+x3+u2+u3);
              mt += power(board[i-1][3], x3+x4+u3+u4);
              mt += power(board[i-1][4], x4+u4);
              m = max(m, dp[i-1][u1][u2][u3][u4]+mt);
            }
          dp[i][x1][x2][x3][x4] = m;
        }
    }

    cout<<dp[5][0][0][0][0]<<endl;
  }
}