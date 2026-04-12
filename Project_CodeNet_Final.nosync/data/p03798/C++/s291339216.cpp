#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <cctype>
#include <numeric>
using namespace std;

#define REP(i,b,n) for(int (i)=b; (i)<(int)(n); ++(i))
#define rep(i,n) REP(i,0,n)
#define foreach(c,i) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define all(a) (a).begin(),(a).end()
#define print(var) cout<<#var":"<<(var)<<endl;
#define printkv(key,var) cout<<#key":"<<(var)<<endl;
#define updatemax(dst,src) dst=max(dst,src);
#define updatemin(dst,src) dst=min(dst,src);

typedef long long ll;

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
  if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

int N;
string S;

int animal[100012];

const int sheep = 1;
const int wolf = -1;

string ans() {
  string ret(N, ' ');

  rep(i,N) {
    ret[i] = animal[i] == 1 ? 'S' : 'W';
  }
  return ret;
}

bool check() {
  if (animal[0] == sheep) {
    if (S[0] == 'o') {
      if (animal[1] != animal[N-1]) return false;
    }
    else {
      if (animal[1] == animal[N-1]) return false;
    }
  }
  else {
    if (S[0] == 'o') {
      if (animal[1] == animal[N-1]) return false;
    }
    else {
      if (animal[1] != animal[N-1]) return false;
    }
  }

  for(int i=1;i<N;i++) {
    if (animal[i] == sheep) {
      if (S[i] == 'o') {
        if (animal[i-1] != animal[i+1]) return false;
      }
      else {
        if (animal[i-1] == animal[i+1]) return false;
      }
    }
    else {
      if (S[i] == 'o') {
        if (animal[i-1] == animal[i+1]) return false;
      }
      else {
        if (animal[i-1] != animal[i+1]) return false;
      }
    }
  }

  return true;
}

string solve() {
  for (int Z = 0; Z < 4; Z++) {
    memset(animal, 0, sizeof(animal)); // 1 => sheep, -1 => wolf, 0 => init
    if (Z <= 1) {
      animal[0] = animal[N] = sheep;
      if (S[0] == 'o') {
        if (Z == 0) {
          animal[1] = animal[N-1] = sheep;
        }
        else {
          animal[1] = animal[N-1] = wolf;
        }
      }
      else {
        if (Z == 0) {
          animal[1] = sheep;
          animal[N-1] = wolf;
        }
        else {
          animal[1] = wolf;
          animal[N-1] = sheep;
        }
      }
    }
    else {
      animal[0] = animal[N] = wolf;
      if (S[0] == 'o') {
        if (Z == 2) {
          animal[1] = sheep;
          animal[N-1] = wolf;
        }
        else {
          animal[1] = wolf;
          animal[N-1] = sheep;
        }
      }
      else {
        if (Z == 2) {
          animal[1] = animal[N-1] = sheep;
        }
        else {
          animal[1] = animal[N-1] = wolf;
        }
      }
    }
    for (int i = 1; i < N; i++) {
      int anim = animal[i];
      char code = S[i];

      if (i == N-1) {
        if (check()) return ans();
      }

      if (anim == sheep) {
        if (code == 'o') {
          animal[i+1] = animal[i-1];
        }
        else {
          animal[i+1] = -animal[i-1];
        }
      }
      else {
        if (code == 'o') {
          animal[i+1] = -animal[i-1];
        }
        else {
          animal[i+1] = animal[i-1];
        }
      }
    }
  }
  return "-1";
}

int main() {
  while (cin >> N >> S) {
    cout << solve() << endl;
  }
}
