#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <utility>
#include <cctype>
#include <list>
#include <bitset>
#include <unordered_set>

using namespace std;

#define FORALL(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORB(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef long double ld;
typedef complex<ld> vec;

typedef pair<ll,int> plli;
typedef pair<int,int> pii;
typedef map<int,int> mii;

#define pb push_back
#define mp make_pair

#define MAXN 3005

int s[MAXN][MAXN];
int choose[MAXN][MAXN];
int two_to_x_mod_pm1[MAXN];
int two_to_two_to_n[MAXN];
int two_to_n[MAXN*MAXN];

int pw(int a, int p, int PRIME) {
  if (p==0) return 1%PRIME;
  int x = pw(a,p/2,PRIME);
  x = 1ll*x%PRIME*x%PRIME;
  if (p%2) x = 1ll*x%PRIME*a%PRIME;
  return x;
}

int main() {
  int N,PRIME;
  scanf("%d%d",&N,&PRIME);

  two_to_x_mod_pm1[0] = 1%(PRIME-1);
  FORALL(n,1,MAXN-1) {
    two_to_x_mod_pm1[n] = two_to_x_mod_pm1[n-1]*2%(PRIME-1);
  }

  // init choose[n][k]
  memset(choose,0,sizeof(choose));
  FORALL(n,0,MAXN-1) {
    choose[n][0] = 1;
    FORALL(k,1,n) choose[n][k] = (choose[n-1][k-1] + choose[n-1][k])%PRIME;
  }

  // init stirling[n][k]
  memset(s,0,sizeof(s));
  FORALL(n,0,MAXN-1) {
    s[n][0] = 1;
    FORALL(k,1,n) s[n][k] = (s[n-1][k-1] + 1ll*(k+1)*s[n-1][k])%PRIME;
  }

  // init two_to_two_to_n
  FORALL(n,0,MAXN-1) {
    two_to_two_to_n[n] = pw(2, two_to_x_mod_pm1[n], PRIME);
  }

  // init two_to_n
  two_to_n[0] = 1%PRIME;
  FORALL(n,1,MAXN*MAXN - 1) {
    two_to_n[n] = two_to_n[n-1]*2ll%PRIME;
  }

  int ans = 0;
  int mult = 1;
  FORALL(c,0,N) {
    FORALL(k,0,c) {

      ll here = 1ll * choose[N][c] % PRIME * s[c][k] % PRIME * two_to_two_to_n[N-c] % PRIME * two_to_n[k*(N-c)] % PRIME;
      ans = (1ll*ans + PRIME + 1ll*mult * here%PRIME)%PRIME;
    }

    mult = 1ll*mult*(PRIME-1)%PRIME;
  }

  cout << ans << endl;
}












