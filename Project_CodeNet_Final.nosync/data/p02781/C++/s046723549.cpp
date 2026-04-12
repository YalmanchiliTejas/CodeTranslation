#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  int n=s.size();
  int k;
  cin >> k;
  ll dp[n][k+1][2];
  rep(i,n)rep(j,k+1)rep(l,2) dp[i][j][l]=0;
  reverse(s.begin(),s.end());
  for(int i =n-1;i>=0;i--){
    //i==n-1のとき
    if(i==n-1){
      int cn = s[i] -'0';
      //      cout << cn << endl;
      dp[i][0][1] = 1;
      dp[i][1][0] = 1;
      dp[i][1][1] = cn-1;
      continue;
    }
       
    //1->1
    rep(ki,k+1){
      dp[i][ki][1] += dp[i+1][ki][1];//0       
    }
    rep(ki,k){
      dp[i][ki+1][1] += dp[i+1][ki][1]*9;//1-9
      //      cout << dp[i+1][ki][1]*9 << endl;
      //      cout << dp[i][ki+1][1] << endl;
    }
    int cn = s[i] -'0';
    //0->1
    if(cn!=0){
      //0
      rep(ki,k+1){
	dp[i][ki][1] += dp[i+1][ki][0];
      }
      rep1(j,cn-1){
	rep(ki,k){
	  dp[i][ki+1][1] += dp[i+1][ki][0];
	}	      
      }
    }
    //0->0
    if(cn==0){
      rep(ki,k+1){
	dp[i][ki][0] += dp[i+1][ki][0];
      }
    }    
    else{
      rep(ki,k){
	dp[i][ki+1][0] += dp[i+1][ki][0];
      }
    }
  }
      //  cout << dp[0][k][0] << endl;
  cout << dp[0][k][1] + dp[0][k][0] << endl;

  
  return 0;
    

}
