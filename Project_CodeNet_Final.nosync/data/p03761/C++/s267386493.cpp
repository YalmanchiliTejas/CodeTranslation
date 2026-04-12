#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
static const int INF = 2000000000;



int main(){
  int n;
  cin >> n;
  vector<vector<int>> d(n, vector<int>(26, 0));
  rep(i, n){
    string s;
    cin >> s;
    rep(j, s.size()){
      int ind = s[j] - 'a';
      d[i][ind]++;
    }
  }
  
  string ans = "";
  rep(i, 26){
    int x = 100;
    char tmp = i + 'a';
    rep(j, n){
      x = min(x, d[j][i]);
    }
    rep(k, x){
      ans += tmp;
    }
  }
  cout << ans << endl;
}