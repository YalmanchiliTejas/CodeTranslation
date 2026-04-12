#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <complex>
#include <vector>
#include<limits>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const long double pi = 3.141592653589793;

#define debug(x) cout << #x << " = " << (x) << endl;
#define rep(i, n) for(int i = 0;i < n;i++)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define F first
#define S second

// #define COMMENT

/*

const int NN = 200090;
ll fact[NN];
ll finv[NN];
ll inv[NN];

void inverse_modulao() {
  fact[0] = fact[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;

  for(int i = 2;i < NN;i++) {
    fact[i] = fact[i-1]*i%mod;
    inv[i] = mod-mod/i*inv[mod%i]%mod;
    finv[i] = finv[i-1]*inv[i]%mod;
  }
}

ll nCr(int n, int r) {
  return fact[n]*finv[r]%mod*finv[n-r]%mod;
}

*/

unsigned long long ans[505][505];
unsigned long long U[505], V[505];
bool S[505], T[505], tans[505][505];
bool ubit, vbit, uop, vop;
int rsum[505], csum[505], N;

int cell_type(bool xbit, bool xop) {
  /*
    (&,0)->2->4
    (&,1)->3->8
    (|,0)->0->1
    (|,1)->1->2

    &=1
    |=0
  */

  return 1 << ((xop << 1) | xbit);

}

void print_tans() {
  rep(j, N) {
    rep(k, N) {
      cout << tans[j][k] << " ";
    }
    cout << endl;
  }
  cout << "------------"<<endl;
}

int main() {

//  freopen("input.in","r",stdin);
//  freopen("output.out","w",stdout);

  cin >> N;
  rep(i, N) {cin >> S[i];S[i]=!S[i];}
  rep(i, N) {cin >> T[i];T[i]=!T[i];}
  rep(i, N) cin >> U[i];
  rep(i, N) cin >> V[i];

  rep(i, 64) {
    rep(u, N) rsum[u] = csum[u] = 0;
    // debug(i);
    rep(j, N) {
      ubit = U[j] & (1ULL << i);
      uop = S[j];
      rep(k, N) {
        vbit = V[k] & (1ULL << i);
        vop = T[k];
        tans[j][k] = 0;

        int x = cell_type(ubit, uop);
        int y = cell_type(vbit,vop);
        if(x + y == 9) {
          // debug(ubit);
          // debug(uop);
          // debug(j);
          // debug(k);
          cout << -1 << endl;
          return 0;
        }
        if(x == 8 || y == 8) tans[j][k] = 1;

        rsum[j] += tans[j][k];
        csum[k] += tans[j][k];
      }
    }
    // cout << "Test" << endl;

    rep(j, N) {
      ubit = U[j] & (1ULL << i);
      uop = S[j];
      vbit = V[j] & (1ULL << i);
      vop = T[j];
      if(cell_type(ubit, uop) == 4 && rsum[j] == N) {
        cout << -1 << endl;
        return 0;
      }
      if(cell_type(vbit, vop) == 4 && csum[j] == N) {
        cout << -1 << endl;
        return 0;
      }
    }

    rep(j, N) {
      ubit = U[j] & (1ULL << i);
      uop = S[j];

      if(cell_type(ubit, uop) == 2 && rsum[j] == 0) {
        rep(k, N) {
          vbit = V[k] & (1ULL << i);
          vop = T[k];
          if(cell_type(vbit, vop) == 2) {
            tans[j][k] = 1;
            rsum[j] += 1;
            csum[k] += 1;
            break;
          }
        }

        if(rsum[j] == 0) {
          rep(k, N) {
            vbit = V[k] & (1ULL << i);
            vop = T[k];
            if(cell_type(vbit, vop) == 4) {
              if(csum[k]+1< N) {
                tans[j][k] = 1;
                rsum[j] += 1;
                csum[k] += 1;
                break;
              }
            }
          }
        }

        if(rsum[j] == 0) {
          cout << -1 << endl;
          return 0;
        }

      }
    }

    // may fail because of this
    rep(k, N) {
      vbit = V[k] & (1ULL << i);
      vop = T[k];

      if(cell_type(vbit, vop) == 2 && csum[k] == 0) {
        rep(j, N) {
          ubit = U[j] & (1ULL << i);
          uop = S[j];
          if(cell_type(ubit, uop) == 2) {
            tans[j][k] = 1;
            rsum[j] += 1;
            csum[k] += 1;
            break;
          }
        }

        if(csum[k] == 0) {
          rep(j, N) {
            ubit = U[j] & (1ULL << i);
            uop = S[j];
            if(cell_type(ubit, uop) == 4) {
              if(rsum[j]+1< N) {
                tans[j][k] = 1;
                rsum[j] += 1;
                csum[k] += 1;
                break;
              }
            }
          }
        }

        if(csum[k] == 0) {
          cout << -1 << endl;
          return 0;
        }

      }
    }

    // update ans
    rep(j, N) {
      rep(k, N) {
        ans[j][k] |= ((1ULL*tans[j][k]) << i);
      }
    }

    // print_tans();
  }

  rep(i,N) {
    rep(j,N) cout << ans[i][j] << " ";
    cout << endl;
  }

  return 0;
}
