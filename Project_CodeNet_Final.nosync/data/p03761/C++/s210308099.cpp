#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n) for(int i=1;i<=(n);i++)
#define lol long long
#define mp make_pair
#define fi first
#define se second
#define pu push_back
#define SYOU(x) setprecision(x+1)
#define abs(x,y) (max(x,y)-min(x,y))
#define SUM(n) ((n)+1)*(n)/2
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = (1e9)+7;
#define all(v) v.begin(),v.end()
using namespace std;
using pii = pair<int,int>;
typedef vector<int> vit;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;
  string s;
  int alpha[50][50] = {};
  rep(i,n){
    cin >> s;
    rep(j, s.size()){
      alpha[i][s[j] - 'a'] ++;
    }
  }
  rep(i, 26){
    int minv = INF;
    rep(j, n){
      minv = min(minv, alpha[j][i]);
    }
    rep(j, minv){
      cout << (char)('a' + i);
    }
  }
  cout << '\n';
  return 0;
}
