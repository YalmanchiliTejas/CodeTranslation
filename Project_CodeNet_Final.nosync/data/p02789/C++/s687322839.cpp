#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define downque(que) priority_queue<ll> que;
#define upque(que) priority_queue<ll, vector<int>, greater<int>> que;
typedef long long ll;
typedef vector<vector<int>> Matrix;
const int MOD = 1e9 + 7;
const int MAX = 1e7;
const int INF = numeric_limits<int>::max();


int main(){
  int n,m;
  string res;
  
  cin >> n >> m;
  if(n-m!=0)
    res = "No";
  else
    res = "Yes";
  cout << res << endl;

}
