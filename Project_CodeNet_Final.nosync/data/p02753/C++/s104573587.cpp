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

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(void) {
  string s;
  cin >> s;

  if(s[0]==s[1] && s[1]==s[2]){
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}
