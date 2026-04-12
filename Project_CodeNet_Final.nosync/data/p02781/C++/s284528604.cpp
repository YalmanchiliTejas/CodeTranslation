#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int k;
string n;
int dp[100][4][2];

int main(){
  cin >> n >> k;
  dp[0][0][1] = 1;
  dp[0][1][1] = n.at(0)-'1';
  dp[0][1][0] = 1;
  for(int i = 1; i < n.size(); i++){
    dp[i][0][1] = dp[i-1][0][1];
    
    dp[i][1][1] = 9 * dp[i-1][0][1] + dp[i-1][1][1] + (n.at(i) == '0' ? 0 : dp[i-1][1][0]);
    dp[i][1][0] = n.at(i) == '0' ? dp[i-1][1][0] : 0;
    
    dp[i][2][1] = dp[i-1][2][1] + 9*dp[i-1][1][1] + dp[i-1][1][0] *  max(n.at(i) - '1', 0) + (n.at(i) == '0' ? 0 : dp[i-1][2][0]);
    dp[i][2][0] = n.at(i) == '0' ? dp[i-1][2][0] : dp[i-1][1][0];
    
    dp[i][3][1] = dp[i-1][3][1] + 9*dp[i-1][2][1] + dp[i-1][2][0] *  max(n.at(i) - '1', 0) +  (n.at(i) == '0' ? 0 : dp[i-1][3][0]);
    dp[i][3][0] = n.at(i) == '0' ? dp[i-1][3][0] : dp[i-1][2][0];
  }
  dp[n.size()-1][0][1]--;
  cout << dp[n.size() - 1][k][0] + dp[n.size() - 1][k][1] <<endl;
}
  