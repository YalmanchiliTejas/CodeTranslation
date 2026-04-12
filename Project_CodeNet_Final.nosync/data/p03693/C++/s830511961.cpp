#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <cassert>
#include <memory>
#include <stack>
#include <set>
#include <map>
#include <cctype>
#include <climits>
#include <list>
#include <queue>

#define INF 1000000000
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a[3];
  for(int i=0; i<3; i++) {
    cin>>a[i];
  }
  int b = a[0] * 100 + a[1] * 10 + a[2];

  string ans;
  if(b % 4 == 0) {
    ans = "YES";
  } else {
    ans = "NO";
  }
  cout<<ans<<endl;
}
