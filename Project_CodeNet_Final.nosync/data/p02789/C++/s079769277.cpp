#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#include <cstdio>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <regex>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(obj) obj.begin(), obj.end()
#define UNIQUE(v) v.erase(unique(All(v)), v.end());
typedef long long ll;

typedef pair<int, int> P;
vector<P> vecp;
int dx[4] = {1, 0, -1, 0}; int dy[4] = {0, 1, 0, -1};

#define N 1000
// input

signed main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n,m;
  cin >> n >> m;
  if (n <= m){
    cout << "Yes";
  }else{
    cout << "No";
  }
}