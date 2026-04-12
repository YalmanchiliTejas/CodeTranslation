#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <complex>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << (x) << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010

string makestr(int L, string s, string t){

  int p = s.size();
  int q = t.size();
  int tt = 0;
  
  while(L%p){
    L -= q;
    tt++;
  }

  string ans;

  while(L){
    L -= p;
    ans += s;
  }

  while(tt--){
    ans += t;
  }

  return ans;
}

int main(){
  int L;
  string s,t;
  int m,n;

  cin >> L >> s >> t;

  string a = makestr(L, s, t);
  string b = makestr(L, t, s);

  assert(a.size() == L);
  assert(b.size() == L);
  
  cout << min(a,b) << endl;
  
  return 0;
}
