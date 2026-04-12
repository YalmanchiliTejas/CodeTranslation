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

int n;
vector<string> s(50);

int main(){
  cin >> n;
  rep(i, n) cin >> s[i];
  int pnt = 0;
  rep(i, n) if(s[pnt].size() > s[i].size()) pnt = i;

  string candidate;
  rep(i, s[pnt].size()){
    const char c = s[pnt][i];
    bool flag = true;
    rrep(j, n-1){
      if((int)s[j].find(c) != -1){
        s[j].erase(s[j].begin() + s[j].find(c));
      }
      else{
        flag = false;
        break;
      }
    }
    if(flag) candidate.push_back(c);
  }
  sort(candidate.begin(), candidate.end());
  cout << candidate << endl;
  return 0;
}
