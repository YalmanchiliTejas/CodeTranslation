#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <bitset>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);++i)
#define all(i,n) (i),(i+n)

int dx4[4]={1,0,-1,0};
int dy4[4]={0,-1,0,1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};

typedef pair<int, int> P;
typedef pair<string, int> SP;
typedef long long ll;

// --------------------------------------
int n, a[21];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  REP(i, n) {
    cin >> a[i];
  }

  int sum = 0;
  int ma = a[0];
  REP(i, n) {
    if(ma <= a[i]) {
      sum++;
      ma = a[i];
    }
  }

  cout << sum << endl;
}
