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

ll N;
vll A(300000, -1*INF);
vll dp(300000, -1*INF); //dp.at(i)は最初からi桁目まで
vvll dp2(300000, vll(2, -1*INF));

int main(){
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  //偶数桁まで
  dp2.at(2).at(0) = A.at(0);
  dp2.at(2).at(1) = A.at(1);
  for(int i = 2; i < N; i+=2){
    dp2.at(i+2).at(0) = dp2.at(i).at(0) + A.at(i);
    dp2.at(i+2).at(1) = max(dp2.at(i).at(0) + A.at(i+1), dp2.at(i).at(1) + A.at(i+1));
  }
  for(int i = 2; i <= N; i+=2){
    dp.at(i) = max(dp2.at(i).at(0), dp2.at(i).at(1));
  }
  
  dp.at(1) = 0;
  dp.at(3) = max(A.at(0), max(A.at(1), A.at(2)));
  for(int i = 3; i <= N; i+=2){
    dp.at(i+2) = max(dp.at(i+1), dp.at(i) + A.at(i+1));
  }
  cout << dp.at(N) << endl;
}