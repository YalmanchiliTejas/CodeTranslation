//wawando's template

#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <set>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>  //clock_t , clock() , CLOCKS_PER_SEC
#include <cstring>
#include <cctype>
#include <climits> // LLONG_MAX , LLONG_MIN , INT_MAX , INT_MIN

//MACROS
#define pb              push_back
#define mp              make_pair
#define INF             1000000000     //1 billion safer for floyd warshall, avoid overflow

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	//ios::sync_with_stdio(false);
  int N, Hi, ans = 0, max = -1;
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &Hi);
    if(Hi >= max) {
      max = Hi;
      ans++;
    }
  }
  printf("%d\n", ans);

  return 0;
}
