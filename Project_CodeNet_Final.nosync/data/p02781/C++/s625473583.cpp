#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;

ll MOD = 1000000007;

int main()
{
  string s;
  int m;
  cin >> s >> m;
  int n = s.size();
  
  //dp[i文字目(0-indexed)まで見た][非0をj個使った][sより小さいことが確定しているか]
  vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m+1, vector<ll>(2, 0)));
  
  //初期化
  rep(i,s[0]-'0'+1)
  {
    if(i == 0) dp[0][0][1]++;
    else if(i < s[0]-'0') dp[0][1][1]++;
    else if(i == s[0]-'0') dp[0][1][0]++;
  }
  //rep(i, m+1)cout<<dp[0][i][0]<<" ";cout<<endl; rep(i,m+1)cout<<dp[0][i][1]<<" ";cout<<endl;
  
  for(int i = 0; i+1 < n; i++)
  {
    int c = s[i+1] - '0';
    //k=1からはk=1にしか遷移しない
    //i桁目で0を選んだ時のkの値がs[i]によって変わる(s[i]==0 -> k=0, s[i]!=0 -> k=1)
    if(c==0)
    {
      //よこ（0を選ぶ）
      rep(j, m+1)
      {
        dp[i+1][j][0] += dp[i][j][0];
        dp[i+1][j][1] += dp[i][j][1];
      }
      //ななめ（非0を選ぶ）
      rep(j, m)
      {
        //k=1からの遷移なので1~9すべて選べる
        dp[i+1][j+1][1] += dp[i][j][1] * 9;
      }
    }
    else
    {
      //0をとる
      rep(j, m+1)
      {
        dp[i+1][j][1] += dp[i][j][0];
        dp[i+1][j][1] += dp[i][j][1];
      }
      //非0を選ぶ
      rep(j, m)
      {
        dp[i+1][j+1][1] += dp[i][j][1] * 9;
        //1以上s[i]未満を選ぶ
        dp[i+1][j+1][1] += dp[i][j][0] * (c-1);
        //s[i]と同じ数を選ぶ
        dp[i+1][j+1][0] += dp[i][j][0];
      }
    }
  }
  
  cout << dp[n-1][m][0] + dp[n-1][m][1] << endl;
  
  /*
  rep(i,n){rep(j,m+1)cout<<dp[i][j][1]<<" "; cout<<"\n";}cout<<endl;
  rep(i,n){rep(j,m+1)cout<<dp[i][j][0]<<" "; cout<<"\n";}
  //*/
  return 0;
}