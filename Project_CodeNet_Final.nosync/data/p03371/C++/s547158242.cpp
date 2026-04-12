#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int main(){
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  ll cmax = max(2*X, 2*Y);
  ll result = INF;
  for(int i = 0; i <= cmax; i++){
    ll money = 0;
    ll anum = max(0LL, X - i/2);
    ll bnum = max(0LL, Y - i/2);
    money = A * anum + B * bnum + C * i;
    chmin(result, money);
  }
  cout << result << endl;
}
