#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define DSORT(c, type) sort(ALL(c), greater<type>())

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int x; cin >> x;
  int y[3] = {3, 5, 7};

  for(int i=0; i<3; ++i)
    if(x == y[i]){ cout << "YES\n"; return 0; }

  cout << "NO\n";

  return 0;
}
