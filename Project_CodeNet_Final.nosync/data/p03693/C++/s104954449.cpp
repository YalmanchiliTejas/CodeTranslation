#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define INF 2e9
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int r,g,b;
  cin>>r>>g>>b;
  if((r*100+g*10+b)%4==0){
    cout<<"YES"<<'\n';
  }
  else{
    cout<<"NO"<<'\n';
  }
  return(0);
}
