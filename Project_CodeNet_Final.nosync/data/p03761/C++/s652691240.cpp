#define _GLIBCXX_DEBUG
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <queue>
#include <bitset>
#include <stack>

typedef long long ll;
typedef std::vector< int > VI;

const double EPS = 1e-10;
const double PI  = acos(-1);
const ll     INF = 1 << 30;

int main(int argc, char* argv[])
{
  int n;
  std::cin >> n;

  std::vector< std::string > vs(n, "");


  for (int i = 0; i < n; i++) {
    std::cin >> vs[i];
    std::sort(vs[i].begin(), vs[i].end());
  }

  std::vector< std::string::iterator > vit(n);
  for (int i = 0; i < n; i++) {
    vit[i] = vs[i].begin();
  }

  std::string ans = "";
  std::string::iterator it;
  for (it = vs[0].begin(); it != vs[0].end(); it++) {
    int cnt = 1;
    for (int i = 1; i < n; i++) {
      std::string::iterator it2;
      while(vit[i] != vs[i].end()) {
	if (*it > *vit[i]) {
	  vit[i]++;
	} else {
	  if (*it == *(vit[i])) {
	    cnt++;
	    vit[i]++;
	  }
	  break;
	}
      }
    }
    if (cnt == n) {
      ans.push_back(*it);
    }
  }
  std::cout << ans << std::endl;

  return 0;
}
