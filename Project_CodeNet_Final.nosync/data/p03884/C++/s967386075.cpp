#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const int INF=1e9;
//const int MOD=998244353;
const long long LINF=1e18;
#define int long long
//template
int dp[10][700];
//main
signed main(){
  int K;cin>>K;
  dp[0][0]++;
  for(int k=1;k<=600;k++)for(int i=1;i<=8;i++)for(int j=0;j<=i;j++)dp[i][k]+=dp[j][k-1];
  string s="FESTIVA";
  reverse(s.begin(),s.end());
  string ans;
  for(int k=600;k>0;k--){
    int a=K/dp[8][k];ans+=string(a,'L');
    K-=dp[8][k]*a;
    ans+=s;
  }
  reverse(ans.begin(),ans.end());
  cout<<ans<<endl;
}

/*
解説AC
大きい方から順番に決めるそれだろうとは思ったけどいい構成方法が思い浮かばず
600って数字そのまま使ったのはよくないね、しっかり自分で計算くらいはしてみないと
とりあえず適当にだんだん大きくなる数字作ってLを間に入れていけばいいって認識でいいんだろうか
*/
