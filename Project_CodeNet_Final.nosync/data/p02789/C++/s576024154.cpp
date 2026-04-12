/*input
*/
#define debug 0
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef double db;
const int N = 1e7 + 5, M = 1e9 + 7; const db eps = 1e-8;
typedef vector<ll> vi; typedef vector<vi> vii;
void solve();
void print(){cout<<'\n';}template<class T,class ...U>void print(T x, U ...y){cout<<x<<' ';print(y...);}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << setprecision(2) << fixed;
  if(debug){freopen("main.cpp","r",stdin);string x;cin>>x;}
  solve();
}
//

void solve() {
  int n, m;
  cin >> n >> m;
  if (n == m) puts("Yes");
  else puts("No");
}
