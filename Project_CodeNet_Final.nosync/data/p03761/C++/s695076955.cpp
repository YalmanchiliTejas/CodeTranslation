#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

const int INF = 50;
int main(){
  int n;
  cin >> n;
  string s[n];
  rep(i,n) {
    cin >> s[i];
  }

  string ans;
  for (char c='a'; c<='z'; c++){
    int small = INF;
    rep(i,n){
      int cnt = 0;
      rep(j,s[i].length()){
        if (s[i][j] == c){
          cnt++;
        }
      }
      small = min(small,cnt);
    }
    rep(i,small) ans += c;
  }

  cout << ans << endl;
}
