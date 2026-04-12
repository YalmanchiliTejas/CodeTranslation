#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <cctype>
#include <bitset>
#include <cassert>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;
const int DIV = 1e9+7;

int n, m;
int rins[9][9];

int main(){
  cin >> n >> m;
  memset(rins, sizeof(rins), 0);
  int inp1,inp2;
  rep(i, m){
    cin >> inp1 >> inp2;
    rins[inp1][inp2] = 1;
    rins[inp2][inp1] = 1;
  }
  vi v;
  vi c;
  int ans = 0;
  bool flag;
  for(int i = 2; i <= n; i++) v.push_back(i);

  do{
    c.clear();
    c.push_back(1);
    rep(i, n-1) c.push_back(v[i]);

    flag = true;
    rep(i, n-1) if(rins[c[i]][c[i+1]] == 0) flag = false;
    if(flag) ans++;
  }while(next_permutation(v.begin(), v.end()));

  cout << ans << endl;

  return 0;
}
