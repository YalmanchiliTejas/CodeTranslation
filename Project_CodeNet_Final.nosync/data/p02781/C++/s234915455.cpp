#include<bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2*1e5 + 1)
#define F first
#define S second
#define endl "\n"
#define MOD (lli)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
#define DEBUG if(0) cout << "aqui" << endl;
#define PI 2 * acos(0.0)
typedef pair<int,int> ii;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

string s;
int k;

int dp[101][3][9];
// int vis[101][3][9];

lli solve(int pos, bool can, int kk) {

  if(pos == s.size()){
    return (kk == k ? 1 : 0);
  }
  if(kk > k) return 0;

  if(dp[pos][can][kk] != -1) return dp[pos][can][kk];

  int atual = s[pos] - '0';
  lli ans = 0;

  for(int i=0;i<=9;i++){
    if(can or i <= atual) {
      bool pode = can;
      if(i < atual) pode = true;
      ans += solve(pos+1, pode, i > 0 ? (kk+1) : kk);
    } 
  }

  return dp[pos][can][kk] = ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;
  cin >> k;

  memset(dp, -1, sizeof dp);

  cout << solve(0, 0, 0) << endl;

  return 0;
}