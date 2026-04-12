#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
using ll = long long;
using P = pair<int,int>;

int main(void) {
  int x;
  cin >> x;

  if(x==7 || x==5 ||x==3) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}