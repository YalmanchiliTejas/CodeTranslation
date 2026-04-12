#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1LL << 30;

ll ncr(ll n, ll r){
  if(n < r) return 0;
  if(r > n-r) r = n-r;

  ll a = 1, b = 1;
  for(int i = 0; i < r; i++){
    a *= (n - i);
  }
  for(int i = 0; i < r; i++){
    b *= (i + 1);
  }
  return a/b;
}

int main(){
  string N;
  cin >> N;
  int ketaN = N.size();
  int K;
  cin >> K;
  vector<vvll> dp(110, vvll(2, vll(4, 0)));
  dp.at(0).at(1).at(0) = 1; //0
  dp.at(0).at(1).at(1) = N.at(0)-'0' - 1; //その桁の数未満
  dp.at(0).at(0).at(1) = 1; //そのもの
  for(int i = 0; i < ketaN-1; i++){
    int D = N.at(i+1)-'0';
    for(int j = 0; j < 2; j++){
      for(int k = 0; k <= 3; k++){
        for(int l = 0; l <= (j? 9: D); l++){
          if(l != 0){
            if(k == 3) continue;
            dp.at(i+1).at(j || (l < D)).at(k+1) += dp.at(i).at(j).at(k);
          }
          else{
            dp.at(i+1).at(j || (l < D)).at(k) += dp.at(i).at(j).at(k);
          }
        }
      }
    }
  }
  cout << dp.at(ketaN-1).at(0).at(K) + dp.at(ketaN-1).at(1).at(K) << endl;
}