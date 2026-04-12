#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
const int MOD = 1000000007;
const int INF = numeric_limits<int>::max() / 2;
typedef pair<int,int> P;
using Graph = vector<vector<int>>;

signed main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;
  if(S[0] == S[1] && S[1] == S[2]){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
  }
}