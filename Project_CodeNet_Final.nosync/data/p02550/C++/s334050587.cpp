#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD =  1000000007;
const int INF = 1e11;
using Graph = vector<vector<int>>;

signed main(){
  int N, X, M;
  cin >> N >> X >> M;

  vector<int> kou;
  set<int> num;
  kou.push_back(X);
  num.insert(X);
  int ans = 0;

  for( int i = 1; i < N; i++ ){
    int A = kou[i-1]*kou[i-1];
    A %= M;
    int ichi = 0;
    if( num.count(A) ){
      //繰り返しの前
      for( int j = 0; j < kou.size(); j++ ){
        if( kou[j] == A ){
          ichi = j;
          break;
        }
        ans += kou[j];
      }

      //繰り返し部分の合計
      int roop = 0;
      for( int j = ichi; j < kou.size(); j++ ){
        roop += kou[j];
      }
      ans += (N-ichi)/(kou.size()-ichi)*roop;
      //余り
      int amari = (N-ichi)%(kou.size()-ichi);
      for( int j = ichi; j < ichi+amari; j++ ) ans += kou[j];
      cout << ans << endl;
      return 0;
    }else{
      num.insert(A);
      kou.push_back(A);
    }
  }

  for( int i = 0; i < kou.size(); i++ ) ans += kou[i];
  cout << ans << endl;
}