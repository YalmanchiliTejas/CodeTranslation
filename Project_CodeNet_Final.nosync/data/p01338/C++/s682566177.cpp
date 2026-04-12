#include <bits/stdc++.h>
using namespace std;

const int R = 5;
const int S[] = {0,60,70,80};

bool exist[R][R];
int G[R][R];
int dp[R][R][1<<(R*2)];


void push(int i, int j, int k) {
  G[i][j] = (G[i][j] + k) % 4;
  G[i][j+1] = (G[i][j+1] + k) % 4;
  G[i+1][j] = (G[i+1][j] + k) % 4;
  G[i+1][j+1] = (G[i+1][j+1] + k) % 4;
}

int main() {
  int Tc;
  cin >> Tc;
  while(Tc--) {
    for(int i = 0; i < R; ++i) {
      for(int j = 0; j < R; ++j) {
	cin >> G[i][j];
	exist[i][j] = G[i][j] != 0;
	G[i][j] -= 1;
      }
    }
    fill(dp[0][0], dp[R][0], -1);
    dp[0][0][0] = 0;
    for(int i = 0; i+1 < R; ++i) {
      for(int j = 0; j+1 < R; ++j) {
	for(int b = 0; b < (1<<(R*2)); ++b) {
	  if(dp[i][j][b] == -1) continue;
	  int ni = i, nj = j + 1;
	  if(nj == R-1) {
	    ++ni;
	    nj = 0;
	  }
	  int base;
	  if(j == 0) base = ( ((b>>(1*2))&3) ) % 4;
	  else base = ( ((b>>(0*2))&3) + ((b>>(4*2))&3) + ((b>>(1*2))&3) ) % 4;
	  for(int k = 0; k < 4; ++k) {
	    int nb = (b >> 2) | (k<<(4*2));
	    int d = exist[i][j] ? S[(G[i][j] + base+k)%4] : 0;
	    if(j+1 == R-1 && exist[i][j+1]) {
	      d += S[( G[i][j+1] + ((b>>(1*2))&3) + k ) % 4];
	    }
	    dp[ni][nj][nb] = max(dp[ni][nj][nb], dp[i][j][b] + d);
	  }
	}
      }
    }
    int ans = 0;
    for(int b = 0; b < (1<<(2*R)); ++b) {
      vector<int> v;
      v.push_back(0);
      for(int j = 1; j < R; ++j) {
	v.push_back((b>>(j*2))&3);
      }
      v.push_back(0);
      int sum = 0;
      for(int j = 0; j < v.size(); ++j) {
	if(exist[R-1][j]) sum += S[(G[R-1][j]+v[j]+v[j+1])%4];
      }
      ans = max(ans, dp[R-1][0][b] + sum);
    }
    cout << ans << endl;
  }
  return 0;
}