#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int N = 2e5+5;
const double eps = 1e-8;

string s;
int k;
int dp[105][5][2];

int main(){
  // freopen("input.txt","r",stdin);
  cin>>s>>k;
  dp[0][0][0] = 1;
  for(int i = 0;i < s.size();i++){
    for(int j = 0;j <= k;j++){
      int nd = s[i] - '0';
      for(int m = 0;m < 2;m++){
	for(int n = 0;n < 10;n++){
	  int nj = j,nk = m;	  
	  if(n != 0) nj++;
	  if(nj > k) continue;
	  if(m == 0){
	    if(n > nd) continue;
	    if(n < nd) nk = 1;
	  }
	  dp[i+1][nj][nk] += dp[i][j][m];
	}
      }
    }
  }
  cout<<dp[s.size()][k][0]+dp[s.size()][k][1]<<endl;
  return 0;
}
