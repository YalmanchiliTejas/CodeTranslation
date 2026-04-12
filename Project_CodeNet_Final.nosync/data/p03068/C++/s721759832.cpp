#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
const double EPS = 1e-15;
using ll = long long;
using ull = unsigned long long;
const int inf = 2e9;
const ll INF = 2e18;
const ll MOD = 1e9+7;
const ll MOD1 = 998244353;
typedef pair<int,int> P;

#define REP(i,n) for (int i = 0; i < (n); i++)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
#define mp make_pair

int main(){
  int n,k;
  string s;
  cin >> n >> s >> k;
  k--;
  REP(i,n) {
    if (s[i] == s[k]) cout << s[k] ;
    else cout << "*";
  }
  cout << endl;
  return 0;
}
