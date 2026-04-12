#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#include <cmath>
using namespace std;

int main(){
  int A,B,C,X,Y;
  cin >> A>>B>>C>>X>>Y;
  int ans = 1e9;
  for(int i  =0;i<=max(X,Y);i++){
    int num =0;
    num += i*2*C;
    num += max(X-i,0)*A;
    num += max(Y-i,0)*B;
    ans = min(ans,num);
  }
  cout << ans << endl;
  return 0;
}
