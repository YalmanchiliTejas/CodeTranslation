#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return 1; }
  return 0; }
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return 1; }
  return 0; }

ll MOD = 1000000007;

int main(void){
  int x; cin >> x;
  if(x >= 30) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0; 
}
