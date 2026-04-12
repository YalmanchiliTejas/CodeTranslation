#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
//#define ll long long
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define rep(i, n) REP(i, 0, n)
#define rep_rev(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define all(x) (x).begin(),(x).end()
ll t1,t2;
const ll mod = 1000000007;
const int INF = 1e9;
const ll INFLONG = 1e18;
void swap(ll *x,ll *y){
  ll tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

int main(){
  string s;
  ll k;
  cin >> s >> k;
  ull keta = s.size();
  ll zerocou = 0;
  //vector<vector<ll>> vec(keta+1,vector<ll>(k+1,0));
  vector<vector<vector<ll>>> vec(keta+1,vector<vector<ll>>(k+2,vector<ll>(2,0)));
  vec[0][0][0] = 1;

  rep(i,keta) {
    if (s[i] != '0') {
      zerocou++;
    }
    if (zerocou > k) {
      break;
    }
    vec[i + 1][zerocou][0]++;
  }
  rep(i,keta){
    rep(j,k+1){
      if(s[i] != '0'){
        vec[i+1][j][1] += vec[i][j][0];
        vec[i+1][j+1][1] += vec[i][j][0] * (s[i] - '0' - 1);
      }
      vec[i+1][j][1] += vec[i][j][1];
      vec[i+1][j+1][1] += vec[i][j][1] * 9;
    }
  }
//  rep(i,keta+1){
//    rep(j,k+1){
//      //cout << vec[i][j][0] << " ";
//      cout << vec[i][j][0] + vec[i][j][1] << " ";
//    }
//    cout << endl;
//  }
  cout << vec[keta][k][0] + vec[keta][k][1] << endl;
}