#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<numeric>
using namespace std;
#define INF (1 << 30) - 1
#define LINF 1LL << 60
const int MOD = 1000000007;
using ll = long long;
using P = pair<int, int>;

int dp[110][4][2];

int main(){
  string n;
  int K;
  cin >> n >> K;

  int ns = n.size();
  dp[0][0][0] = 1;
  for(int i = 0; i < ns; ++i){
    int nd = n[i] - '0';
    for(int j = 0; j < 4; ++j){
      for(int k = 0; k < 2; ++k){
        for(int d = 0; d <= (k ? 9 : nd); ++d){
          int nj = j;
          if(d)++nj;
          if(nj > K)continue;
          dp[i + 1][nj][k || (d < nd)] += dp[i][j][k];
        }
      }
    }
  }

  cout << dp[ns][K][0] + dp[ns][K][1] << endl;
  return 0;
}
