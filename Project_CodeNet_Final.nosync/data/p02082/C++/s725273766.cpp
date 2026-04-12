#include<iostream>
#include<string>
#include<cstdio>
#include<deque>
#include<list>
#include<queue>
#include<stack>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<set>
#include<complex>
#include<cmath>
#include<limits>
#include<cassert>
#include<bitset>
#include<numeric>
#include<functional>

using namespace std;


int main(){
  int s, t;
  cin >> s >> t;
  int p, q, m;
  cin >> p >> q >> m;
  int y;
  cin >> y;
  cout << (t ^ s ^ y) << endl;
}

