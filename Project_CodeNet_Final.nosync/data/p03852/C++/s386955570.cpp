#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <set>
#include <string.h>

using namespace std;

typedef long long ll;

#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REP3(i,st,en) for(ll (i)=(st);(i)<(en);(i)++)

using P = pair<ll, ll>;
const int MOD = 1e9+7;
const ll INF = 1e+14;
const double PI = 3.14159265349;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  char c;
  string v = "aiueo"; 
  cin >> c;
  
  cout << ((v.find(c) != string::npos) ? "vowel" : "consonant") << "\n";
  return 0;
}
