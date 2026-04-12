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
#define MOD 1000000007LL

ll N, X;
vll length(51);
vll pnum(51);

ll func(ll lv, ll x){
  if(x == length.at(lv)) return pnum.at(lv);
  ll xx;
  if(x <= length.at(lv)/2){
    xx = x;
    if(xx == 1) return 0;
    return func(lv-1, xx-1);
  }
  else{
    xx = length.at(lv) - x;
    if(xx == 1) return pnum.at(lv);
    return pnum.at(lv) - func(lv-1, xx-1);
  }
}

int main(){
  cin >> N >> X;
  length.at(0) = 1LL;
  pnum.at(0) = 1LL;
  for(int i = 1; i <= N; i++){
    length.at(i) = 2LL * length.at(i-1) + 3LL;
    pnum.at(i) = 2LL * pnum.at(i-1) + 1LL;
  }
  cout << func(N, X) << endl;
}