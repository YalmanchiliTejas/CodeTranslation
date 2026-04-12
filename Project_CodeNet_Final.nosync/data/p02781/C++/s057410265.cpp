#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = s.length();
  vector<vector<int>> dp0(n+1, vector<int>(4, 0)), dp1(n+1, vector<int>(4, 0));
  dp1[0][0] = 1;
  for(int i=1; i<=n; i++){
    dp0[i][0] = 1;
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=3; j++){
      dp0[i][j] = dp0[i-1][j] + dp0[i-1][j-1]*9;
      if(i==n){
        if(s[i-1]-'0'){
          dp0[i][j] += dp1[i-1][j] + dp1[i-1][j-1]*(s[i-1]-'0');
          dp1[i][j] = dp1[i-1][j-1];
        }else{
          dp0[i][j] += dp1[i-1][j];
          dp1[i][j] = dp1[i-1][j];
        }
      }else{
        if(s[i-1]-'0'){
          dp0[i][j] += dp1[i-1][j] + dp1[i-1][j-1]*(s[i-1]-'0'-1);
          dp1[i][j] = dp1[i-1][j-1];
        }else{
          dp1[i][j] = dp1[i-1][j];
        }
      }
    }
  }
  cout << dp0[n][k] << endl;
  return 0;
}
