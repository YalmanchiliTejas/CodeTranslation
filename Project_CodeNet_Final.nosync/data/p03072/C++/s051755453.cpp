#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <regex>
 
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
 
using namespace std;
 
typedef long long ll;

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  vector<ll> h = vector<ll>(n);
  for (int i = 0; i < n; i++){
    cin >> h[i];
  }
  ll res = 0;
  ll high = 0;
  REP(i,n){
    if (i == 0) {
     res ++; 
    }
    else {
      if (high <= h[i]){
        res++;
      }
    }
    high = max(h[i],high);
  }
 cout << res << endl;
  return 0;
}
