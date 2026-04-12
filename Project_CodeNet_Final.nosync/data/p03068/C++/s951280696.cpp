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

#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define SUM(v) accumulate(ALL(v), 0)
#define AVE(v) SUM(v) / (v).size()
// 入力eと同じ値の要素の数
#define COUNT(v, e) count(ALL(v), e)

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;
  int k;
  cin >> k;

  char c = s[k-1];
  for(int i=0; i<n; ++i) 
    if(s[i] != c)
      s[i] = '*';

  cout << s << endl;

  return 0;
}
