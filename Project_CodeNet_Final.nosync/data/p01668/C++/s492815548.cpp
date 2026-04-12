#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int MAXN = 10004;
const int MAXM = 503;

string pattern, A, B;
vector<int> next;
int dp[2][MAXM][2][2], dp2[2][MAXM][2][2];

void make() {
  pattern += "$";
  next = vector<int>(pattern.size()+1);
  next[0] = -1;
  for(int i = 0, j = -1; i < pattern.size(); ++i, ++j, next[i] = j)
    while(j >= 0 && pattern[i] != pattern[j]) j = next[j];
  pattern.resize(pattern.size() - 1);
}

int calc(const string &X) {
  memset(dp, 0, sizeof(dp));
  memset(dp2, 0, sizeof(dp2));
  dp[0][0][0][0] = 1;
  for(int i = 0; i < X.size(); ++i) {
    const int p = i % 2;
    const int q = (i + 1) % 2;
    for(int j = pattern.size()-1; j >= 0; --j) {
      for(int k = 0; k < 2; ++k) {
        for(int z = 0; z < 2; ++z) {
          dp[q][j][k][z] = 0;
          dp2[q][j][k][z] = 0;
        }
      }
    }
    for(int j = pattern.size()-1; j >= 0; --j) {
      for(int k = 0; k < 2; ++k) {
        for(int z = 0; z < 2; ++z) {
          for(char d = '0'; d <= '9'; ++d) {
            if(!k && X[i] < d) break;
            int nk = k || X[i] != d;
            int nz = z || d != '0';
            int ni = i, nj = j;
            int add = 0;
            if(!nz) {
              ni = i+1; nj = 0;
            } else {
              while(ni == i) {
                if(d == pattern[nj]) {
                  ++ni;
                  ++nj;
                } else if(nj == 0) {
                  ++ni;
                  nj = 0;
                } else {
                  nj = next[nj];
                }
              }
            }
            if(nj == pattern.size()) {
              add = 1;
              nj = next[nj];
            }
            ( dp[q][nj][nk][nz] += dp[p][j][k][z] ) %= mod;
            ( dp2[q][nj][nk][nz] +=
              (dp2[p][j][k][z] + add * dp[p][j][k][z] % mod) % mod ) %= mod;

          }
        }
      }
    }
  }
  int res = 0;
  for(int j = pattern.size()-1; j >= 0; --j) {
    for(int k = 0; k < 2; ++k) {
      for(int z = 0; z < 2; ++z) {
        ( res += dp2[X.size()%2][j][k][z] ) %= mod;
      }
    }
  }
  return res;
}

/*
33
133
233
330
331
332
333
the number of "33" in [0,333] is 8
*/

int main() {
  while(cin >> A >> B >> pattern) {
    make();
    int res = (calc(B) - calc(A) + mod) % mod;
    for(int i = 0; i < A.size(); ++i) {
      if(A.substr(i, pattern.size()) == pattern) {
        ( res += 1 ) %= mod;
      }
    }
    cout << res << endl;
  }
  return 0;
}