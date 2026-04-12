#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)

#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define PR0(A,n) { cout << #A << " = "; FORN(_,n) cout << A[_] << ' '; cout << endl; }

// #define FL fflush(stdout)

#define MOD 1000000007
#define INF 2000000000
#define MAXN 60

int GLL(LL& x) {
  return scanf("%lld", &x);
}

int GI(int& x) {
  return scanf("%d", &x);
}

int n;
int cnts[26][MAXN];

int main() {
  cin >> n;
  memset(cnts, 0, sizeof cnts);

  FORN(i, n) {
    string str;
    cin >> str;

    FORN(j, str.size()) {
      int idx = str[j] - 'a';
      cnts[ idx ][i]++;
    }
  }

  vector<char> ans;
  FORN(j, 26) {
    int num = INF;
    char letter = (char)('a' + j);
    FORN(i, n) {
      num = min(num, cnts[j][i]);
    }
    if (num > 0) {
      FORN(k, num) ans.PB(letter);
    }
  }

  string ans2(ans.begin(), ans.end());
  cout << ans2 << "\n";
    
  return 0;
}