#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
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

int main(){
  int n;
  cin >> n;
  vi result(26, INT_INF);
  for(int i = 0; i < n; i++){
    string S;
    cin >> S;
    vi counter(26, 0);
    for(int j = 0; j < S.size(); j++){
      counter.at(S.at(j)-'a')++;
    }
    for(int j = 0; j < 26; j++){
      chmin(result.at(j), counter.at(j));
    }
  }
  for(int i = 0; i < 26; i++){
    for(int j = 0; j < result.at(i); j++){
      cout << (char)(i+'a');
    }
  }
  cout << endl;

}