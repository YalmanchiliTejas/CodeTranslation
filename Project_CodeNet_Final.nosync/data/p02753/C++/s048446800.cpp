#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vector<int>> mat;
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll mod = 1000000007;
const int INF = 1<<29;

int main(){
  string S; cin >> S;
  if (S[0] == S[1] && S[0] == S[2] && S[1] == S[2]) cout << "No" << endl;
  else cout << "Yes" << endl;
}
