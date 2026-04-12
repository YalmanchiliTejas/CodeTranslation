#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vi vector<int>
#define vivi vector<vi>
const int INF = 1<<29;
typedef long long ll;



int dp[100][2][100];//dp[keta][未満である][0でない数の個数]

int main(){
  string N;cin >> N;
  int K;cin >> K;
  int l = N.size();
  vi n;

  for(auto a : N){
    n.push_back(a - '0');
  }
  dp[0][0][0] = 1;
  for(int i = 0;i < l;++i){
    for(int smaller = 0;smaller < 2;++smaller){
      for(int j = 0;j < l;++j){
        for(int x = 0;x <= (smaller ? 9 : n[i]);++x){
          dp[i + 1][smaller || x < n[i]][(x ? j+1 : j)] += dp[i][smaller][j];
        }
      }
    }
  }
  cout << dp[l][0][K]+dp[l][1][K];
}
