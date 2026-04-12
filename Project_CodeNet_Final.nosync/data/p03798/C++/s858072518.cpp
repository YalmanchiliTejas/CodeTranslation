#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS (1e-7)
#define INF (1e9)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const double PI = acos(-1);
const ll MOD = 1000000007;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
///////////////////////////////////////////////////////////////
 
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); //入出力高速化
  int N; cin >> N;
  string s; cin >> s;

  vector<vector<char>> A(N+2, vector<char>(4));
  rep(i,N) {
    if (i == 0) {
      if (s[i] == 'o') {
        A[0][0] = A[1][0] = A[2][0] = A[1][1] = A[0][2] = A[2][3] = 'S';
        A[0][1] = A[2][1] = A[1][2] = A[2][2] = A[0][3] = A[1][3] = 'W';
      } else {
        A[0][0] = A[1][0] = A[2][0] = A[1][1] = A[0][2] = A[2][3] = 'W';
        A[0][1] = A[2][1] = A[1][2] = A[2][2] = A[0][3] = A[1][3] = 'S';
      }
    } else {
      if (s[i] == 'o') {
        rep(j,4) {
          if (A[i][j] == 'S' && A[i+1][j] == 'S') A[i+2][j] = 'S';
          if (A[i][j] == 'S' && A[i+1][j] == 'W') A[i+2][j] = 'W';
          if (A[i][j] == 'W' && A[i+1][j] == 'S') A[i+2][j] = 'W';
          if (A[i][j] == 'W' && A[i+1][j] == 'W') A[i+2][j] = 'S';
        } 
      } else {
        rep(j,4) {
          if (A[i][j] == 'S' && A[i+1][j] == 'S') A[i+2][j] = 'W';
          if (A[i][j] == 'S' && A[i+1][j] == 'W') A[i+2][j] = 'S';
          if (A[i][j] == 'W' && A[i+1][j] == 'S') A[i+2][j] = 'S';
          if (A[i][j] == 'W' && A[i+1][j] == 'W') A[i+2][j] = 'W';
        }
      }
    }
  }
  
  int k = -1;
  rep(j,4) {
    if (A[N][j] == A[0][j] && A[N+1][j] == A[1][j]) {
      k = j;
      break;
    } 
  }

  if (k == -1) cout << k << endl;
  else {
    for (int i = 1; i < N+1; i++) cout << A[i][k];
    cout << endl;
  }
}