#include <iostream>
 
#define N 1000000007
 
using namespace std;
 
typedef unsigned long long int ULLI;
 
int count_ways(ULLI n, ULLI d, ULLI x) {
  int last_i;
  bool has_initialized = false;
  ULLI count_bin[50][2001], count[50][2001];
  for (int i=0; d>0; i++) {
    if (i == 0) {
      for (int j=0; j<=n; j++) {
        if (j < x) {
          count_bin[0][j] = 1;
        }
        else {
          count_bin[0][j] = 0;
        }
      }
    }
    else {
      for (int j=0; j<=n; j++) {
        count_bin[i][j] = 0;
        for (int k=0; k<=j; k++) {
          count_bin[i][j] = (count_bin[i][j]+count_bin[i-1][k]*count_bin[i-1][j-k])%N;
        }
      }
    }
    if (has_initialized) {
      if (d%2 == 0) {
        for (int j=0; j<=n; j++) {
          count[i][j] = count[i-1][j];
        }
      }
      else {
        for (int j=0; j<=n; j++) {
          count[i][j] = 0;
          for (int k=0; k<=j; k++) {
            count[i][j] = (count[i][j]+count[i-1][j-k]*count_bin[i][k])%N;
          }
        }
      }
    }
    else if (d%2 > 0) {
      for (int j=0; j<=n; j++) {
        count[i][j] = count_bin[i][j];
      }
      has_initialized = true;
    }
    d >>= 1;
    last_i = i;
  }
  return count[last_i][n];
}
 
int main() {
  ULLI n, d, x;
  while (true) {
    cin >> n >> d >> x;
    if (n == 0) {
      return 0;
    }
    cout << count_ways(n, d, x) << endl;
  }
}