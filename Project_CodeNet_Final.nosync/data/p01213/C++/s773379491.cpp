#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define REP(i, b, n) for(int i =b; i<(int)n; i++)

using namespace std;

enum{
  DIAG, PREI, PREJ
};

pair<int, string> LCS(const string &a, const string &b){
  int n1=a.length();
  int n2=b.length();
  int dp[1+n1][1+n2];
  int v[1+n1][1+n2];
  string path;

  for(int i=0;i<1+n1;++i){
    for(int j=0;j<1+n2;++j){
      dp[i][j]=0;
      v[i][j]=-1;
    }
  }

  for(int i=0;i<n1;++i){
    for(int j=0;j<n2;++j){
      if(a[i]==b[j]){
	dp[i+1][j+1] = dp[i][j]+1;
	v[i+1][j+1] = DIAG;
      }
      else {
	if(dp[i][j+1] > dp[i+1][j]){
	  dp[i+1][j+1] = dp[i][j+1];
	  v[i+1][j+1] = PREI;
	}
	else {
	  dp[i+1][j+1] = dp[i+1][j];
	  v[i+1][j+1] = PREJ;
	}
      }
    }
  }
  int ni = n1;
  int nj = n2;
  while(v[ni][nj] !=-1){
    if(v[ni][nj] == DIAG){
      path+=(a[ni-1]);
      --ni;
      --nj;
    }
    else if(v[ni][nj] == PREI){
      ni--;
    }
    else {
      nj--;
    }
  }
  reverse(path.begin(), path.end());
  return make_pair(dp[n1][n2], path);
}

int main()
{
  string s;
  while(cin >> s){
    if(s == "#END")break;
    pair<int, string> ans(0, "");
    REP(i, 1, (int)s.length()){
      string a = s.substr(0, i);
      string b = s.substr(i, (s.length()-i));
      ans = max(LCS(a, b), ans);
    }
    cout << ans.second << endl;
  }
  return 0;
}